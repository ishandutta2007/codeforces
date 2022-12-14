//codeforces.com/problemset/problem/468/B
#include<iostream>
#include<vector>
#include<map>
 
struct twosat{
	int n;
	std::vector<std::vector<int>> ad,rad;
	twosat(int n):n(n),ad(2*n),rad(2*n){}
	// cond i: i*2 and i*2+1
 
	void addedge(int a,int b){
		// a implies b
		//std::cerr<<"add "<<a<<' '<<b<<'\n';
		ad[a].push_back(b);
		rad[b].push_back(a);
		if((a^b)!=1){
			ad[b^1].push_back(a^1);
			rad[a^1].push_back(b^1);
		}
	}
 
	std::vector<char> value; // -1: unknown

	bool assign_false(int x){
		//std::cerr<<"assign_false "<<x<<' '<<false<<'\n';
		if(value[x]==false)return true;
		if(value[x]==true)return false;
		value[x]=false;
		value[x^1]=true;
		for(int y:rad[x])
			if(!assign_false(y))
				return false;
		return true;
	}
 
	std::vector<int> order;
	void toposort(int i){ // value = 0/-1: not visited / visited
		if(value[i])return;
		//std::cerr<<"toposort "<<i<<'\n';
		value[i]=-1;
		for(int j:ad[i])
			toposort(j);
		order.push_back(i);
		//std::cerr<<"order push "<<i<<'\n';
	}
 
	bool run(){
		value.clear();value.resize(ad.size());
		order.clear();order.reserve(ad.size());
		// now value = [0] * n
		for(int i=0;i<ad.size();++i)
			toposort(i);
		// now value = [-1 <- filled by toposort] * n
		for(unsigned ix=order.size();ix--;){
			int x=order[ix];
			if(value[x]<0)
				if(!assign_false(x))
					return false;
		}
		return true;
	}
};
 
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,a,b;std::cin>>n>>a>>b;
 
	twosat z(n);
 
	std::vector<int> d(n);
	std::map<int,int> ind;
	for(int i=0;i<n;++i){
		std::cin>>d[i];
		ind[d[i]]=i;
	}
 
	// (x => not x) : not x
	// (not x => x) : x
	// assume 0 = false = in set a
 
	for(int i=0;i<n;++i){
		auto i1=ind.find(a-d[i]);
		auto i2=ind.find(b-d[i]);
		if(i1==ind.end()){
			if(i2==ind.end()){
				std::cout<<"NO\n";
				return 0;
			}
			// both must be in set b
			z.addedge(i*2,i*2+1);
			z.addedge(i2->second*2,i2->second*2+1);
		}else{
			if(i2==ind.end()){
				// both must be in set a
				z.addedge(i*2+1,i*2);
				z.addedge(i1->second*2+1,i1->second*2);
			}else{
				z.addedge(i*2,i1->second*2);
				z.addedge(i*2+1,i2->second*2+1);
			}
		}
	}
 
	if(z.run()){
		std::cout<<"YES\n";
		for(int i=0;i<n;++i)
			std::cout<<char('0'+z.value[i*2+1])<<' ';
		std::cout<<'\n';
	}else
		std::cout<<"NO\n";
}