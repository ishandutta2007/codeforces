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

const int N=100005;
int n,a[N],b[N],mx[N],p[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),p[a[i]]=i;
	For(i,1,n) mx[i]=max(mx[i-1],a[i]);
	int x=n,pp=0;
	for (;x;x=p[mx[x]]-1)
		For(i,p[mx[x]],x) b[++pp]=a[i];
	For(i,1,n) printf("%d ",b[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}