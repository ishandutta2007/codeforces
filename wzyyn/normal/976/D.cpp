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
const int N=1005;
int e[N][N];
int a[N],sum,n;
void divide(int l,int r){
	if (!a[l]) l++,r--;
	if (l>r) return;
	For(i,1,a[r])
		e[a[r]+1][i]=1,++sum;
	For(i,l,r) --a[i];
	divide(l,r);
	
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int m=a[n]+1;
	divide(1,n);
	printf("%d\n",sum);
	For(i,1,m) For(j,1,i-1)
		if (e[i][j]) printf("%d %d\n",i,j);
}