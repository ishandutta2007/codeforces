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
int n,a[35];
void solve(){
	scanf("%d",&n);
	int v=2; *a=0; n--;
	for (;n>=v;a[++*a]=v,n-=v,v*=2);
	if (n) a[++*a]=n;
	a[++*a]=1;
	sort(a+1,a+*a+1);
	printf("%d\n",(*a)-1);
	For(i,2,*a) printf("%d ",a[i]-a[i-1]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}