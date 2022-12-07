#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=50005;
int n,a[N][8];
bool cmp(int x,int y){
	int s=0;
	for (int i=1;i<=5;i++)
		if (a[x][i]<a[y][i])
			++s;
	return s>=3;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=5;j++)
			scanf("%d",&a[i][j]);
	int p=1;
	for (int i=2;i<=n;i++)
		if (cmp(i,p)) p=i;
	for (int i=1;i<=n;i++)
		if (i!=p&&!cmp(p,i)) 
			return puts("-1"),void(0);
	printf("%d\n",p);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}