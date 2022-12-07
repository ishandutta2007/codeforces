#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
#define ll long long
using namespace std;

const int N=1505;
int n,m,h,t;
int a[N][N],b[N][N];
int f[N],id[N],q[N],vi[N];

bool cmp(int x,int y){
	For(i,1,t)
		if (a[x][q[i]]!=a[y][q[i]])
			return a[x][q[i]]<a[y][q[i]];
	return x<y;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m) scanf("%d",&a[i][j]);
	For(i,1,n) For(j,1,m) scanf("%d",&b[i][j]);
	
	For(i,1,m) For(j,1,n-1) f[i]+=(b[j][i]<=b[j+1][i]);
	For(i,1,m) if (f[i]==n-1) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		For(i,1,n-1)
			if (!vi[i]&&b[i][x]!=b[i+1][x]){
				vi[i]=1;
				For(j,1,m) if (f[j]!=n-1){
					f[j]-=(b[i][j]<=b[i+1][j]);
					f[j]++;
					if (f[j]==n-1)
						q[++t]=j;
				}
			}
	}
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	For(i,1,n) For(j,1,m)
		if (a[id[i]][j]!=b[i][j]){
			puts("-1");
			return 0;
		}
	printf("%d\n",t);
	for (;t;--t) printf("%d ",q[t]);
}