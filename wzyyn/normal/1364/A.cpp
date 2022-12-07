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
int n,x,a[100005];
void solve(){
	scanf("%d%d",&n,&x);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) a[i]=(a[i-1]+a[i])%x;
	if (a[0]!=a[n]) printf("%d\n",n);
	else{
		int p1=0,p2=n;
		for (;p1<=n&&a[p1]==a[0];++p1);
		for (;p2>=0&&a[p2]==a[n];--p2);
		printf("%d\n",max(n-p1,p2-0));
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}