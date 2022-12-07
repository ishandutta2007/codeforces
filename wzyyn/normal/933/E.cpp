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
int n,a[N],ans[N];
int fl[N],q[N];
ll f[N];
void work(int x){
	int v=min(a[x],a[x+1]);
	if (!v) return;
	a[x]-=v; a[x+1]-=v; ans[++*ans]=x;	
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		ll v1=f[max(i-2,0)]+a[i];
		ll v2=f[max(i-3,0)]+max(a[i],a[i-1]);
		f[i]=min(v1,v2); fl[i]=(f[i]!=v1);
	}
	int v=n-(f[n-1]<f[n]),cnt=0;
	for (;v;v-=2+fl[v]) q[++cnt]=v;
	reverse(q+1,q+cnt+1);
	For(i,1,cnt){
		int x=q[i-1],y=q[i];
		work(y-1); work(x+1); work(y);
	}
	For(i,0,*ans)
		printf("%d\n",ans[i]);
}