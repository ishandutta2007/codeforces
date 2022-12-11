#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N=2e5+10;
long long l,r;
int n,m;
set<pair<int,int>>st;
vector<int>prod[N];
inline void add(int x){
	for(auto i:prod[x])st.insert({i,x});
}
inline void del(int x){
	for(auto i:prod[x])st.erase(pair<long long,long long>{i,x});
}
signed main(){
	for(int i=1;i<N;i++){
		for(int j=i;j<N;j+=i){
			prod[j].push_back(i);
		}
	}
	scanf("%d%d%lld%lld",&n,&m,&l,&r);
	int nl=m+1,nr=m;
	for(int i=1;i<=n;i++){
		long long kl=l/i,kr=r/i;
		if(i*kl<l)++kl;
		kr=min(kr,m*1ll);
		if(kl>kr){puts("-1");continue;}
		while(kl<nl){
			nl--;
			for(auto i:prod[nl])st.insert({i,nl});
		}
		while(nr>kr){
			for(auto i:prod[nr])st.erase(pair<int,int>{i,nr});
			nr--;
		}
		bool pd=0;
		for(auto a:prod[i]){
			auto it=st.upper_bound({a,1e9});
			if(it==st.end())break;
			int b=(*it).first,y=(*it).second;
			if(1ll*(i/a)*b<=n){
				pd=1;
				printf("%d %d %d %d\n",i,y,i/a*b,y/b*a);
				break;
			}
		}
		if(!pd)puts("-1");
	}
	return 0;
}