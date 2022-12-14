// https://vietnam-national19.kattis.com/problems ?
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<iostream>
#include<string>
#include<numeric>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::string a,b;
	a.reserve(n);
	b.reserve(n);
	std::cin>>a;
	std::cin>>b;
	for(char& c:a) c-='0';
	for(char& c:b) c-='0';
	for(int i=1;i<n;i+=2){
		a[i]=9-a[i];
		b[i]=9-b[i];
	}

	if(std::accumulate(begin(a),end(a),0)!=std::accumulate(begin(b),end(b),0)){
		std::cout<<"-1\n";
	}else{
		std::vector<int> suf(n); // [i] = sum {j>=i} a[j]-b[j]
		int64_t out=0;
		for(int val=0,x=n;x--;){
			suf[x]=val+=a[x]-b[x];
			out+=std::abs(suf[x]);
		}
		std::cout<<out<<'\n';
		for(int i=0,z=(int)std::min(out,(int64_t)100000);z--;){
			while(true){
				if(suf[i]==0) ++i;
				else if(suf[i]<0){
					assert(a[i-1]>(i-1==0 ? 1 : 0));
					if(a[i]==9){
						++i;
						continue;
					}

					--a[i-1];++a[i];
					++suf[i];
					std::cout<<i<<((i&1)?" -1\n":" 1\n");
					if(i>0 and suf[i-1]!=0) --i;
					break;
				}else{
					assert(a[i-1]<9);
					if(a[i]==0){
						++i;
						continue;
					}

					++a[i-1];--a[i];
					--suf[i];
					std::cout<<i<<((i&1)?" 1\n":" -1\n");
					if(i>0 and suf[i-1]!=0) --i;
					break;
				}
			}
		}
	}
}