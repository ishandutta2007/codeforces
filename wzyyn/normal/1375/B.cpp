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
#define all(v) v.begin(),v.end()
using namespace std;

void solve(){
	int n,m,fl=0;
	scanf("%d%d",&n,&m); 
	For(i,1,n) For(j,1,m){
		int x,y=4;
		scanf("%d",&x);
		y-=(i==1)+(i==n)+(j==1)+(j==m);
		if (x>y) fl=1;
	}
	if (fl) puts("NO");
	else{
		puts("YES");
		For(i,1,n) For(j,1,m)
			printf("%d%c",4-(i==1)-(i==n)-(j==1)-(j==m),j==m?'\n':' ');
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}