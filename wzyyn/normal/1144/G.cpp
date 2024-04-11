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
int n,a[N],fl[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int v1=-1,v2=1e9;
	For(i,1,n)
		if (a[i]<=v1&&a[i]>=v2) return puts("NO");
		else if (a[i]>=v2) assert(v1<a[i]),v1=a[i],fl[i]=0;
		else if (a[i]<=v1) assert(v2>a[i]),v2=a[i],fl[i]=1;
		else if (a[i]<a[i+1]) assert(v1<a[i]),v1=a[i],fl[i]=0;
		else assert(v2>a[i]),v2=a[i],fl[i]=1;
	puts("YES");
	For(i,1,n) printf("%d ",fl[i]);
}