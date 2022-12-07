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
	int n;
	scanf("%d",&n);
	if (n<=3) return puts("-1"),void(0);
	for (int i=n-n%2;i>4;i-=2) printf("%d ",i);
	printf("2 4 ");
	for (int i=1;i<=n;i+=2) printf("%d ",i);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
2 4 1 3 5 7 9 11 13 15 17
*/