// This algorithm is not proven to take < 20000 queries. Hacks are welcome.
#ifndef LOCAL
#define NDEBUG
#endif
#include<array>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdlib>

#ifdef LOCAL

int getn(){return 600;}
std::vector<std::pair<int,int>> edges=[]{
	std::vector<std::pair<int,int>> edges;
	for(int i=0;i<300;++i)
	for(int j=300;j<600;++j)
		edges.push_back({i,j});
	edges.push_back({100,199});
	return edges;
}();
/*
int getn(){return 5;}
std::vector<std::pair<int,int>> edges{{0,1},{1,2},{2,3},{3,4},{4,0}};
*/

#include<unordered_set>
int nquery=0;
int ask(auto first,auto last){
	if(nquery==20000){
		std::cerr <<"exceeded\n";
	}
	++nquery;

	/*
	std::unordered_set<int> ss(first,last);
	assert(first+ss.size()==last);
	*/
	std::vector<char> ss(getn());
	std::for_each(first,last,[&](int x){ss[x]=true;});
	int ans{};
	for(auto [a,b]:edges)
		//ans+=(ss.count(a) and ss.count(b));
		ans+=(ss[a] and ss[b]);
	return ans;
}
template<char type>
void report(std::vector<int> const& a){
	std::cerr<<"nquery = "<<nquery<<'\n';
	assert(type=='Y' or type=='N');
	if(type=='N'){
		assert(a.size()%2!=0);
		for(int i=0;i<a.size();++i){
			int x=a[i],y=a[(i+1)%a.size()];
			assert(std::any_of(begin(edges),end(edges),[x,y](std::pair<int,int> e){
						return e==std::make_pair(x,y) or e==std::make_pair(y,x);
						}));
		}
	}else{
		std::unordered_set<int> aa(begin(a),end(a));
		assert(a.size()==aa.size());
		for(auto [x,y]:edges)
			assert(aa.count(x)!=aa.count(y));
	}

	std::cout<<type<<' '<<a.size()<<'\n';
	for(int x:a)std::cout<<' '<<x+1;
	std::cout<<'\n';
}

#else

int getn(){
	int n;std::cin>>n;
	return n;
}
int ask(auto first,auto last){
	std::cout<<"? "<<last-first<<'\n';
	for(auto iter=first;iter!=last;++iter) std::cout<<' '<<*iter+1;
	std::cout<<std::endl;
	int ans;std::cin>>ans;
	if(ans<0){
		std::exit(0);
	}
	return ans;
}
template<char type>
void report(std::vector<int> const& a){
	assert(type=='Y' or type=='N');
	if(type=='N') assert(a.size()%2!=0);

	std::cout<<type<<' '<<a.size()<<'\n';
	for(int x:a)std::cout<<' '<<x+1;
	std::cout<<'\n';
}
#endif

int ask(auto const& container){
	return ask(begin(container),end(container));
}

std::vector<int> join(auto first1,auto last1,auto first2,auto last2){
	std::vector<int> tmp;
	tmp.reserve((last1-first1)+(last2-first2));
	tmp.insert(end(tmp),first1,last1);
	tmp.insert(end(tmp),first2,last2);
	return tmp;
}
auto join(auto const& a,auto const& b){
	return join(begin(a),end(a),begin(b),end(b));
}

int find(auto const& a,int aska,auto first,auto last){
	// find vertex y int [first..last[ such that edge x...y exists for some x int a,
	// assume there exists such y and aska is correct
	// uses 2 * log2(last-first) queries

	assert(first!=last);
	if(last-first==1)return *first;
	auto mid=first+(last-first)/2;

	if(ask(join(begin(a),end(a), first,mid))>aska+ask(first,mid))
		return find(a,aska,first,mid);
	else
		return find(a,aska,mid,last);
}

std::vector<std::vector<int>> ad;
std::vector<int> cycle;
std::vector<char> vis;
int z;
void dd(int x){
	if(vis[x])return;
	vis[x]=true;
	cycle.push_back(x);
	if(x==z){
		report<'N'>(cycle);
		std::exit(0);
	}
	for(int y:ad[x])
		dd(y);
	assert(cycle.back()==x);
	cycle.pop_back();
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const n=getn();
	std::vector<int> a{n-1},b,rest(n-1);
	for(int z=n-1;z--;)rest[z]=z;

	int aska=0,askb=0;
	ad.resize(n);

	while(not rest.empty()){
		assert(not a.empty());

		auto askar=ask(join(a,rest));
		auto askr=ask(rest);
		if(askar>aska+askr){
			auto x=find(a,aska,begin(rest),end(rest));
			assert(ask(join(begin(a),end(a),&x,1+&x))>aska); // x is connected to a

			if(not b.empty()){
				auto askbx=ask(join(begin(b),end(b),&x,1+&x));
				if(askbx>askb){ // found cycle
					int y=find(std::array<int,1>{x},0,begin(a),end(a));
					z=find(std::array<int,1>{x},0,begin(b),end(b));
					cycle.assign(1,x);
					vis.resize(n);
					dd(y);
					assert(false);
				}
				askb=askbx;
			}else
				assert(askb==0);

			// add edge to ad
			int y=find(std::array<int,1>{x},0,begin(a),end(a));
			ad[x].push_back(y);
			ad[y].push_back(x);

			// add x to b
			rest.erase(std::find(begin(rest),end(rest),x));
			b.push_back(x);
		}else{
			assert(ask(join(b,rest))>askb+askr); // because graph is connected

			auto x=find(b,askb,begin(rest),end(rest));
			assert(ask(join(begin(b),end(b),&x,1+&x))>askb); // x is connected to b

			// add edge to ad
			int y=find(std::array<int,1>{x},0,begin(b),end(b));
			ad[x].push_back(y);
			ad[y].push_back(x);

			// add x to a
			rest.erase(std::find(begin(rest),end(rest),x));
			a.push_back(x);
			aska=ask(a);
		}
	}

	report<'Y'>(a);
}