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
const int N=2005;
char s[10];
int n,fl,x,a[N][N],id[N][N];
int q[N*N],v[N],pos[N],f[N*2],mat[N];
bool cmp(int x,int y){
	return (v[x]>v[y])^fl;
}
void solve(){
	int n;
	scanf("%d",&n);
	For(i,1,n) For(j,1,n) scanf("%d",&a[i][j]);
	puts("B"); fflush(stdout);
	scanf("%s%d",s+1,&x);
	fl=(s[1]=='D')^(x<=n);
	int h=0,t=0;
	For(i,1,n) mat[i]=0;
	For(i,1,n){
		q[++t]=i;
		pos[i]=1;
		For(j,1,n){
			v[j]=a[i][j];
			id[i][j]=j;
		}
		sort(id[i]+1,id[i]+n+1,cmp);
	}
	while (h!=t){
		int x=q[++h];
		for (;;){
			int y=id[x][pos[x]++];
			if (!mat[y]||(a[mat[y]][y]>a[x][y])^fl){
				if (mat[y]) q[++t]=mat[y];
				mat[y]=x;
				break;
			}
		}
	}
	For(i,1,n){
		f[i+n]=mat[i];
		f[mat[i]]=i+n;
	}
	printf("%d\n",f[x]);
	fflush(stdout);
	for (;;){
		scanf("%d",&x);
		if (x<0) break;
		printf("%d\n",f[x]);
		fflush(stdout);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}