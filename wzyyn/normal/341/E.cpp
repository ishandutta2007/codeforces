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
const int N=1005;
const int M=300005;
int n,top,cnt;
int q[N],a[N];
pii ans[M];
void ins(int x,int y){
	assert(a[x]<=a[y]);
	ans[++cnt]=pii(x,y);
	a[y]-=a[x]; a[x]*=2;
}
void solve(int &x,int &y,int &z){
	for (;;){
		if (a[x]>a[y]) swap(x,y);
		if (a[x]>a[z]) swap(x,z);
		if (a[y]>a[z]) swap(y,z);
		if (!a[x]) break;
		int v=a[y]/a[x];
		for (int vv=1;vv<=v;vv<<=1)
			v&vv?ins(x,y):ins(x,z);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) if (a[i]) q[++top]=i;
	if (top<=1) return puts("-1"),0;
	for (;top>=3;--top)
		solve(q[top],q[top-1],q[top-2]);
	printf("%d\n",cnt);
	For(i,1,cnt) printf("%d %d\n",ans[i].fi,ans[i].se);
}