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
const int N=200005;
int n,m,k,id[N],a[N],dis1[N],disn[N],q[N];vector<int>G[N];
void ae(int k1,int k2){G[k1].push_back(k2);}
void bfs(int k1,int*dis){
	for(int i=1;i<=n;++i)dis[i]=0x3f3f3f3f3f3f3f3fll;
	int he=0,ta=0;q[++ta]=k1,dis[k1]=0;
	while(he!=ta){
		k1=q[++he];
		for(auto j:G[k1])if(dis[j]==0x3f3f3f3f3f3f3f3fll){
			dis[j]=dis[k1]+1;
			q[++ta]=j;
		}
	}
}
signed main(){
	rd(n),rd(m),rd(k);
	for(int i=1;i<=k;++i)rd(a[i]);
	for(int i=1;i<=m;++i){
		int k1,k2;rd(k1),rd(k2);
		ae(k1,k2),ae(k2,k1);
	}
	bfs(1,dis1);
	bfs(n,disn);
	for(int i=1;i<=k;++i)id[i]=i;
	sort(id+1,id+1+k,[&](int k1,int k2){return dis1[a[k1]]<dis1[a[k2]];});
	int ans=0;
	for(int i=1;i<k;++i){
		for(int j=1;j<5&&i+j<=k;++j){
			int k1=a[id[i]],k2=a[id[i+j]];
			if(abs(dis1[k1]-dis1[k2])<=1){
				pt(dis1[n],'\n');
				return 0;
			}
			ans=max(ans,min(dis1[k1]+disn[k2]+1,dis1[k2]+disn[k1]+1));
		}
	}
	ans=min(ans,dis1[n]);
	pt(ans,'\n');
	return 0;
}