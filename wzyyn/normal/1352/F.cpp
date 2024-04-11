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

void solve(){
	int n0,n1,n2;
	scanf("%d%d%d",&n0,&n1,&n2);
	if (!n1){
		if (!n0) For(i,1,n2+1) putchar('1');
		else For(i,1,n0+1) putchar('0');
	}
	else{
		For(i,1,n0+1) putchar('0');
		For(i,1,n2+1) putchar('1');
		For(i,2,n1) putchar('0'+(i&1)); 
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}