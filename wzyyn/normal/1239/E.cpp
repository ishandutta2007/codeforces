#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
bitset<1250005> f[52][26];
int n,S,a[55],ans[4][26];
int main(){
	scanf("%d",&n);
	For(i,1,2*n) scanf("%d",&a[i]);
	sort(a+1,a+2*n+1,greater<int>());
	ans[1][1]=a[2*n];
	ans[2][n]=a[2*n-1];
	f[0][0][0]=1;
	For(i,1,2*n-2) S+=a[i];
	For(i,1,2*n-2) For(j,0,min(n-1,i-1)){
		f[i][j]|=f[i-1][j];
		f[i][j+1]|=f[i-1][j]<<a[i];
	}
	int v=1<<30,p=-1;
	For(i,0,S) if (f[2*n-2][n-1][i])
		if (max(S-i,i)<=v)
			v=max(S-i,i),p=i;
	int v1=2*n-2,v2=n-1;
	int p1=2,p2=n-1;
	for (;v1;v1--)
		if (p>=a[v1]&&v2&&f[v1-1][v2-1][p-a[v1]])
			ans[1][p1++]=a[v1],v2--,p-=a[v1];
		else ans[2][p2--]=a[v1];
	For(i,1,2) For(j,1,n)
		printf("%d%c",ans[i][j],j==n?'\n':' ');
}