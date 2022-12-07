#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=100005;
ll mo,a[N];
int n,f[N],g[N];
int la[N],now[N];
bool cmp(int x,int y){
	return (a[x]&(mo-1))<(a[y]&(mo-1));
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	For(i,1,n) a[i]=a[n]-a[i];
	sort(a+1,a+n+1);
	For(i,0,n) f[i]=1<<30,la[i]=i;
	f[n]=0;
	For(b,0,60){
		mo=1ll<<(b+1);
		ll moo=mo>>1;
		For(i,1,n) now[i]=i;
		sort(now+1,now+n+1,cmp);
		int val=0,p1=n,p2=n;
		For(i,1,n) val+=((a[i]&moo)!=0);
		For(i,0,n) g[i]=1<<30;
		Rep(i,n,0){
			int S1=val,S2=n-val;
			ll pref=moo-(a[la[i]]&(moo-1))-1;
			for (;p1&&pref+(a[now[p1]]&(mo-1))>=mo;p1--);
			for (;p2&&pref+moo+(a[now[p2]]&(mo-1))>=mo;p2--);
			g[p1]=min(g[p1],f[i]+S1);
			g[p2]=min(g[p2],f[i]+S2);
			if (a[la[i]]&(mo>>1)) val--;
			else val++;
		}
		For(i,0,n) f[i]=g[i];
		For(i,1,n) la[i]=now[i];
	}
	printf("%d\n",f[n]);
}