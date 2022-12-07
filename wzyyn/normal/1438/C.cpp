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
int n,m;
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m){
		int x;
		scanf("%d",&x);
		if ((i+j+x)%2==1) x++;
		printf("%d%c",x,j==m?'\n':' ');
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}