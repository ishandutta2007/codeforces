#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int K=20,M=5005;
int k,n[K],a[K][M];
int vis[K],nxt[K],val[K];
int f[66666],fr[66666];
pii pos[66666];
ll S[K],sum;
map<ll,int> mp;
int main(){
	scanf("%d",&k);
	For(i,1,k){
		scanf("%d",&n[i]);
		For(j,1,n[i]){
			scanf("%d",&a[i][j]);
			mp[a[i][j]]=i;
			S[i]+=a[i][j];
			sum+=a[i][j];
		}
	}
	if (sum%k) return puts("No"),0;
	For(i,1,k) For(j,1,n[i]){
		int p=i,sta=0,v=a[i][j];
		for (;;){
			sta|=1<<(p-1);
			ll nxv=sum/k-(S[p]-v);
			if (mp.find(nxv)==mp.end()){
				sta=-1; break;
			}
			p=mp[nxv]; v=nxv;
			if (sta&(1<<(p-1))) break;
		}
		if (p==i&&v==a[i][j]&&sta!=-1)
			pos[sta]=pii(i,a[i][j]);
	}
	f[0]=1;
	For(i,0,(1<<k)-1){
		int rest=(1<<k)-1-i;
		if (!f[i]) continue;
		for (int j=rest;j;j=(j-1)&rest)
			if (pos[j].fi){
				f[i|j]=1;
				fr[i|j]=j;
			}
	}
	if (!f[(1<<k)-1]) return puts("No"),0;
	for (int sta=(1<<k)-1;sta;){
		int st=fr[sta]; sta-=st;
		int p=pos[st].fi,v=pos[st].se;
		for (;;){
			ll nxv=sum/k-(S[p]-v);
			nxt[mp[nxv]]=p; val[p]=v;
			p=mp[nxv]; v=nxv;
			if (p==pos[st].fi) break;
		}
	}
	puts("Yes");
	For(i,1,k) printf("%d %d\n",val[i],nxt[i]);
}