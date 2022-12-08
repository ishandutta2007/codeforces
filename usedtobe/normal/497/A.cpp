#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define N 1005
using namespace std;
int n,m,cnt;bool b[N];
char a[N][N];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",a[i]+1);
	rep(j,1,m) {
		bool f=1;
		rep(i,2,n) if (a[i][j]<a[i-1][j]&&!b[i]) {f=0;break;}
		if (!f) ++cnt;
		else rep(i,2,n)if(a[i][j]>a[i-1][j]) b[i]=1;
	}
	printf("%d\n",cnt);
	return 0;
}