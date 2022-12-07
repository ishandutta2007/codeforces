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
const int N=1000005;
int n,x[N],y[N];
int main(){
	scanf("%d",&n);
	if (n&1) return puts("NO"),0;
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	x[n+1]=x[1]; y[n+1]=y[1]; n/=2;
	For(i,1,n)
		if (x[i+1]-x[i]!=x[i+n]-x[i+n+1]||
			y[i+1]-y[i]!=y[i+n]-y[i+n+1])
				return puts("NO"),0;
	puts("YES");
}