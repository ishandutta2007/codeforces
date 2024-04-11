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
int n;
void solve(){
	scanf("%d",&n);
	int s=(n+3)/4;
	For(i,1,n-s) putchar('9');
	For(i,1,s) putchar('8');
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}