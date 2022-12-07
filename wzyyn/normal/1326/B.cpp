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
const int N=200005;
int n,a[N],b[N],v;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&b[i]);
	For(i,1,n) if (b[i]>0) a[i]=v=(v+=b[i]);
	else a[i]=v+b[i];
	v=0;
	For(i,1,n) v=min(v,a[i]);
	For(i,1,n) printf("%d ",a[i]);
}