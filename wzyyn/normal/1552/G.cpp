#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

int n,k;
int a[45][45];
long long b[45][45],c[45];
long long Mask[45];
int bic[1<<20|5];
void init(){
	for (int i=0;i<1<<20;i++)
		bic[i]=bic[i>>1]+(i&1);
}
#define BICOUNT(x) (bic[(x)>>20]+bic[(x)&1048575])
bool dfs(int x,long long S){
	if (x==k){
		int v=BICOUNT(S);
		if (S!=(1ll<<n)-(1ll<<(n-v))) return 0;
		return 1;
	}
	++x;
	int l=BICOUNT(S&c[x]); S-=S&c[x];
	int r=l+BICOUNT(Mask[x]^Mask[x-1]);
	for (int i=l;i<=r;i++)
		if (!dfs(x,S|b[x][i]))
			return 0;
	return 1;
}
int main(){
	init();
	scanf("%d%d",&n,&k);
	if (n==1) return puts("ACCEPTED"),0;
	if (k==0) return puts("REJECTED"),0;
	for (int i=1;i<=k;i++){
		int m;
		scanf("%d",&m);
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
		sort(a[i]+1,a[i]+m+1,greater<int>());
		for (int j=1;j<=m;j++)
			b[i][j]=b[i][j-1]|(1ll<<(a[i][j]-1));
		Mask[i]=Mask[i-1]|b[i][m];
		c[i]=b[i][m];
	}
	if (Mask[k]!=(1ll<<n)-1)
		return puts("REJECTED"),0;
	puts(dfs(0,0)?"ACCEPTED":"REJECTED");
	
}