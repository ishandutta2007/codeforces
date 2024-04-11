/*
Contest: -
Problem: Codeforces 1408G
Author: tzc_wk
Time: 2020.10.2
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
const ll MOD=998244353;
int n=read(),a[1505][1505],c[1505][1505];
pii b[1505][1505];
int key[1505];
int hs[1505],ord[1505];
inline bool cmp(int x,int y){
	return hs[x]<hs[y];
}
int fa[1505*50],lst[1505*50],concnt=0;
vector<ll> dp[1505*50];
signed main(){
	srand(time(0));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		a[i][j]=read(),c[i][j]=a[i][j];
	for(int i=1;i<=n;i++) sort(c[i]+1,c[i]+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) b[i][j]=make_pair(a[i][j],j);
		sort(b[i]+1,b[i]+n+1);
	}
	for(int i=1;i<=n;i++) key[i]=rand()<<15|rand();
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++) hs[i]^=key[b[i][j].se];
		for(int i=1;i<=n;i++) ord[i]=i;
		sort(ord+1,ord+n+1,cmp);
		int l=1,r=1;
		while(l<=n){
			while(r<=n&&hs[ord[l]]==hs[ord[r]]) r++;
			if(r-l==j){
				bool flag=1;
				if(j!=n){
					int mn=0x3f3f3f3f;
					for(int i=l;i<r;i++) mn=min(mn,c[ord[i]][j+1]);
					for(int i=l;i<r;i++) if(c[ord[i]][j]>mn) flag=0;
				}
				if(!flag){l=r;continue;}
				concnt++;
//				printf("%d: ",concnt);
//				for(int i=l;i<r;i++) printf("%d ",ord[i]);
//				puts("");
				for(int i=l;i<r;i++){
					if(lst[ord[i]]) fa[lst[ord[i]]]=concnt;
					lst[ord[i]]=concnt;
				}
			}
			l=r;
		}
	}
	for(int i=1;i<=concnt;i++) dp[i].resize(1,1),dp[i][0]=1;
	for(int i=1;i<=concnt;i++){
		if(dp[i].size()==1){
			dp[i][0]=0;
			dp[i].push_back(1);
		} else {
			dp[i][1]=(dp[i][1]+1)%MOD;
		}
		int j=fa[i];if(j==0) continue;
		vector<ll> tmp;tmp.resize(dp[i].size()+dp[j].size()-1);
		for(int x=0;x<dp[i].size();x++){
			for(int y=0;y<dp[j].size();y++){
				tmp[x+y]=(tmp[x+y]+1ll*dp[i][x]*dp[j][y]%MOD)%MOD;
			}
		}
		dp[j].clear();dp[j].resize(tmp.size());
		for(int k=0;k<dp[j].size();k++) dp[j][k]=tmp[k];
	}
	for(int i=1;i<=n;i++) printf("%d ",dp[concnt][i]);
	return 0;
}