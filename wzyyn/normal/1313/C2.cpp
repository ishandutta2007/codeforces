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
const int N=500005;
int n,a[N],q[N];
ll v[N],vl[N],vr[N];
void solve(ll *vv){
	int t=0;
	For(i,1,n){
		vv[i]=vv[i-1];
		int s=1;
		for (;t&&a[q[t]]>=a[i];t--)
			vv[i]-=1ll*v[t]*a[q[t]],s+=v[t];
		vv[i]+=1ll*s*a[i];
		q[++t]=i; v[t]=s;
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	solve(vl);
	reverse(a+1,a+n+1);
	solve(vr);
	reverse(a+1,a+n+1);
	ll ans=-1,ansp=0;
	For(i,1,n)
		if (vl[i]+vr[n-i+1]-a[i]>ans)
			ans=vl[i]+vr[n-i+1]-a[i],ansp=i;
	//cout<<ans<<' '<<ansp<<endl;
	For(i,ansp+1,n) a[i]=min(a[i],a[i-1]);
	Rep(i,ansp-1,1) a[i]=min(a[i],a[i+1]);
	For(i,1,n) printf("%d ",a[i]);
}