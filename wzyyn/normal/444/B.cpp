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
const int B=200;
const int N=100005;
int n,x,seed,q[N];
int a[N],b[N],c[N];
int Rand(){
	return seed=(seed*37ll+10007)%1000000007;
}
int main(){
	scanf("%d%d%d",&n,&x,&seed);
	For(i,1,n) a[i]=i,b[i]=(i<=x);
	For(i,1,n) swap(a[i],a[Rand()%i+1]);
	For(i,1,n) swap(b[i],b[Rand()%i+1]);
	For(i,1,n) if (b[i]) q[++*q]=i;
	For(i,1,n) if (a[i]>=n-B+1)
		For(j,1,n-i+1) if (b[j]) c[i+j-1]=max(c[i+j-1],a[i]);
	For(i,1,n) if (!c[i])
		For(j,1,*q) if (q[j]<=i)
			c[i]=max(c[i],a[i-q[j]+1]);
	For(i,1,n) printf("%d\n",c[i]);
	puts("");
}