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
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=1000005;
int n;
pii mp[N];
ll a[N],b[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]),a[i]+=a[i-1];
	For(i,1,n) scanf("%lld",&b[i]),b[i]+=b[i-1];
	bool fl=(a[n]>b[n]);
	For(i,1,n) if (fl) swap(a[i],b[i]);
	For(i,0,n-1) mp[i]=pii(-1,-1);
	int p=0;
	For(i,0,n){
		for (;b[p]<a[i];++p);
		if (mp[b[p]-a[i]].fi==-1) mp[b[p]-a[i]]=pii(i,p);
		else{
			int v=b[p]-a[i];
			if (!fl){
				printf("%d\n",i-mp[v].fi);
				For(j,mp[v].fi+1,i) printf("%d ",j); puts("");
			}
			printf("%d\n",p-mp[v].se);
			For(j,mp[v].se+1,p) printf("%d ",j); puts("");
			if (fl){
				printf("%d\n",i-mp[v].fi);
				For(j,mp[v].fi+1,i) printf("%d ",j); puts("");
			}
			exit(0);
		}
	}
}