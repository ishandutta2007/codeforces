#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=200005;
int n,a[N],b[N],d[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),d[i]=0;
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		++d[x]; ++d[y];
	}
	ll ans=0;
	For(i,1,n) ans+=a[i];
	printf("%lld ",ans);
	*b=0;
	For(i,1,n) For(j,2,d[i]) b[++*b]=a[i];
	sort(b+1,b+*b+1);
	Rep(i,*b,1) printf("%lld ",ans+=b[i]);
	puts(""); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();	
}