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
int n,a[100005];
void solve(){
	int x=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),x^=a[i];
	if (!x) puts("DRAW");
	else{
		int sum=0;
		For(i,0,29) if (x&(1<<i))
			if (x!=(1<<i)) x-=(1<<i);
		For(i,1,n) sum+=((a[i]&x)!=0);
		puts((sum+1)%4||n%2==0?"WIN":"LOSE");
	}
}
/*
10:WIN
30:LOSE
11:WIN

*/
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}