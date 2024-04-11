#include<set>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005;
int T,n,m,c[N];
vector<int>G[N];
map<vector<int>,int>mmp;
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		mmp.clear(); 
		for(int i=1;i<=n;++i)G[i].clear(),rd(c[i]);
		for(int i=1;i<=m;++i){
			int x,y;rd(x),rd(y);
			G[y].push_back(x);
		}
		for(int i=1;i<=n;++i){
			sort(G[i].begin(),G[i].end());
			if(G[i].size()>0)mmp[G[i]]+=c[i];
		}
		int ans=0;
		for(auto x:mmp)ans=__gcd(ans,x.second);
		pt(ans,'\n');
	}
	return 0;
}