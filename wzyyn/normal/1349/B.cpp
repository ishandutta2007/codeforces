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
int n,x,a[100005],b[100005];
void solve(){
	scanf("%d%d",&n,&x);
	bool flag=0;
	For(i,1,n) scanf("%d",&a[i]),flag|=(x==a[i]);
	if (!flag) return puts("no"),void(0);
	if (n==1) return puts("yes"),void(0);
	For(i,1,n) b[i]=(b[i-1]+(a[i]<x?-1:1));
	int mn=0; flag=0;
	For(i,2,n){
		if (b[i]>mn) flag=1;
		mn=min(mn,b[i-1]);
	}
	puts(flag?"yes":"no");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}