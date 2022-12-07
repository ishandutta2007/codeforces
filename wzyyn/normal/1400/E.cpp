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
int n,a[5005];
int divide(int l,int r,int v){
	if (l>r) return 0;
	if (l==r) return (a[l]!=v);
	int p=l;
	For(i,l,r) if (a[i]<a[p]) p=i;
	return min(divide(l,p-1,a[p])+divide(p+1,r,a[p])+a[p]-v,r-l+1);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	cout<<divide(1,n,0)<<endl;
}