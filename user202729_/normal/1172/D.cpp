#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	struct portal{
		int x1,y1,x2,y2;
		void print()const{
			std::cout<<x1+1<<' '<<y1+1<<' '<<x2+1<<' '<<y2+1<<'\n';
		}
	};

	int n;std::cin>>n;
	std::vector<int> r(n),c(n),rpos(n),cpos(n);

	for(int i=0;i<n;++i){
		int ri;std::cin>>ri;--ri;
		r[i]=ri;
		rpos[ri]=i;
	}
	for(int i=0;i<n;++i){
		int ci;std::cin>>ci;--ci;
		c[i]=ci;
		cpos[ci]=i;
	}

	std::vector<portal> out;
	for(int i=0;i<n;++i){
		if(r[i]==i and c[i]==i)
			continue;
		int j=rpos[i],k=cpos[i];
		std::swap(r[i],r[j]); std::swap(rpos[r[i]],rpos[r[j]]);
		std::swap(c[i],c[k]); std::swap(cpos[c[i]],cpos[c[k]]);
		out.push_back({j,i, i,k});
	}
	std::cout<<out.size()<<'\n';
	for(portal p:out)p.print();
}