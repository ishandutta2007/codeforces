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
int ans[55];
void solve(){
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if (n*a!=m*b) return puts("NO"),void(0);
	puts("YES");
	int p=1;
	For(i,1,n){
		memset(ans,0,sizeof(ans));
		For(j,1,a) ans[p]=1,p=p%m+1;
		For(j,1,m) printf("%d",ans[j]);
		puts("");
	}
}
/*
na=mb
n/b=m/a
*/
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}