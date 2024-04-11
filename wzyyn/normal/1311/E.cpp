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
const int N=5005;
int l[N],r[N],nd,fa[N];
void init(){
	For(i,1,N-1){
		l[i]=i-1+l[(i-1)/2]+l[i-1-(i-1)/2];
		For(j,0,i-1) r[i]=max(r[i],r[j]+r[i-1-j]+i-1);
	}
}
void solve(int n,int d,int rt){
	d-=n-1;
	For(j,0,n-1)
		if (l[j]+l[n-j-1]<=d&&d<=r[j]+r[n-j-1]){
			int v=min(d-l[j]-l[n-j-1],r[j]-l[j])+l[j];
			if (j) fa[++nd]=rt,solve(j,v,nd);
			if (n-j-1) fa[++nd]=rt,solve(n-j-1,d-v,nd);
			return;
		}
}
void solve(){
	int n,d;
	scanf("%d%d",&n,&d);
	if (d<l[n]||d>r[n]) return puts("NO"),void(0);
	solve(n,d,nd=1);
	puts("YES");
	For(i,2,n) printf("%d ",fa[i]);
	puts("");
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}