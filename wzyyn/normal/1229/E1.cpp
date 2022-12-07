#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int mo=1000000007;
int n,S,cnt[250],id[250];
int f[10][250];
vector<int> vec[10];
map<pll,int> mp;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int DP(int x,ll sta){
	if (!sta) return 0;
	if (x==n) return 1;
	if (mp.find(pll(x,sta))!=mp.end()) return mp[pll(x,sta)];
	++S; int ans=0;
	For(j,1,(1<<n)-1){
		ll nxt=0;
		For(k,0,vec[x].size()-1){
			if (!(sta&(1ll<<k))) continue;
			int las=vec[x][k];
			For(l,0,n-1)
				if ((j&(1<<l))&&!(las&(1<<l)))
					nxt|=1ll<<id[las|(1<<l)];
		}
		ans=(ans+1ll*f[x][j]*DP(x+1,nxt))%mo;
	}
	//printf("dfs_state %d %lld\n",x,sta);
	return mp[pll(x,sta)]=ans;
}
int main(){
	scanf("%d",&n);
	int I100=power(100,mo-2);
	For(i,0,n-1){
		f[i][0]=1;
		For(j,0,n-1){
			int P;
			scanf("%d",&P);
			int p1=1ll*P*I100%mo;
			int p0=(1+mo-p1)%mo;
			For(k,0,(1<<j)-1){
				f[i][k|(1<<j)]=1ll*f[i][k]*p1%mo;
				f[i][k]=1ll*f[i][k]*p0%mo;
			}
		}
		//For(j,0,(1<<n)-1) printf("%d ",f[i][j]); puts("");
	}
	For(i,0,(1<<n)-1)
		cnt[i]=cnt[i/2]+(i&1);
	For(i,0,(1<<n)-1){
		vec[cnt[i]].PB(i);
		id[i]=vec[cnt[i]].size()-1;
	}
	printf("%d\n",DP(0,1));
}