#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=2005;
int n,a[N],fa[N],vi[N];
int vx[N],vy[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int find(int v){
	if (v<=0) return 2*n+1;
	int p=lower_bound(a+1,a+2*n+1,v)-a;
	if (a[p]!=v) return 2*n+1;
	p=get(p);
	if (a[p]!=v) return 2*n+1;
	return p;
}
bool check(int v){
	For(i,0,2*n+1) vi[i]=0,fa[i]=i;
	int p=2*n;
	For(i,1,n){
		for (;vi[p];--p);
		vi[p]=1; fa[p]=p+1;
		int nv=find(v-a[p]);
		if (nv==2*n+1) return 0;
		vx[i]=a[p],vy[i]=a[nv];
		vi[nv]=1; fa[nv]=nv+1;
		v=max(a[p],a[nv]);
	}
	printf("YES\n");
	printf("%d\n",vx[1]+vy[1]);
	For(i,1,n) printf("%d %d\n",vx[i],vy[i]);
	return 1;
}
void solve(){
	scanf("%d",&n);
	For(i,1,2*n) scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	For(i,1,2*n-1) if (check(a[i]+a[2*n])) return;
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}