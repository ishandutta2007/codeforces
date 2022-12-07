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
const int N=200005;
int n,a[N];
char s[N];
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int mn=0,mx=0;
	For(i,1,n){
		a[i]=a[i-1]+(s[i]=='0'?1:-1);
		mn=min(mn,a[i]); mx=max(mx,a[i]);
	}
	printf("%d\n",mx-mn);
	For(i,1,n) printf("%d ",max(a[i-1],a[i])-mn);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}