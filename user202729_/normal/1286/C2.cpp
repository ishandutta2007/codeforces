// Misread the problem statement (total number of substrings over all queries)
// :(

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<array>

int n;

struct edge{
	int x,fi,se;
};
std::vector<std::vector<edge>> ad;

std::vector<std::string> query(int l,int r){
	assert(0<=l and l<r and r<=n);
	std::cout<<"? "<<l+1<<' '<<r<<std::endl;
	std::vector<std::string> a((r-l)*(r-l+1)/2);

	std::vector<std::array<int,26>> totalbylen(r-l+1);

	for(auto& row:a){
		std::cin>>row;
		std::sort(begin(row),end(row));
		for(char c:row)
			++totalbylen[row.size()][c-'a'];
	}

	if(r-l==1)
		ad[l].push_back({l,a[0][0]-'a',a[0][0]-'a'});

	std::array<int,26> last{};
	for(unsigned i=2;i<totalbylen.size();++i){
		std::array<int,26> cur{};
		for(int c=0;c<26;++c)
			cur[c]=totalbylen.back()[c]- (totalbylen[i][c]-totalbylen[i-1][c]);

		// cur = sum of outside len (i-1) from two prefixes
		std::vector<int> opt;
		for(int c=0;c<26;++c){
			for(int z=(cur[c]-last[c]);z--;)
				opt.push_back(c);
		}
		assert(opt.size()==2);

		auto x=l+i-2;
		auto y=r-i+1;
		ad[x].push_back({y,opt[0],opt[1]});
		ad[y].push_back({x,opt[0],opt[1]});

		last=cur;
	}

	return a;
}

std::string out;
struct invalid_value{};
void dd(int x){
	int valx=out[x];
	assert(valx>=0 and valx<26);
	for(auto [y,fi,se]:ad[x]){
		if(y==x){
			if(fi!=valx or fi!=se) throw invalid_value{};
		}

		if(valx!=fi and valx!=se) throw invalid_value{};
		int valy=fi+se-valx;
		if(valy>=26) throw invalid_value{};
		if(out[y]>=0){
			if(out[y]!=valy) throw invalid_value{};
		}else{
			out[y]=valy;
			dd(y);
		}
	}
}

int main(){
	std::cin>>n;
	ad.resize(n);
	auto a=query(0,n);

	if(n==1){
		std::cout<<"! "<<a[0]<<'\n';
		return 0;
	}

	auto const& all=*std::max_element(begin(a),end(a),[](auto const& x,auto const& y){return x.size()<y.size();});
	assert(all.size()==n);

	query(0,n/2);
	if(n>2) query(n/2,n-1);

	//std::sort(begin(a),end(a));
	//std::sort(begin(b),end(b));
	//std::sort(begin(c),end(c));

	out.assign(n,-1);
	for(int x=0;x<n;++x) if(out[x]<0){
		for(int c=0;;++c){
			assert(c<26);
			auto bkp=out;
			out[x]=c;

			try{
				dd(x);
			}catch(invalid_value){
				out=bkp;
				continue;
			}
			break;
		}
	}

	for(char& c:out) c+='a';
	std::cout<<"! "<<out<<'\n';
}