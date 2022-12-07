#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=55,M=2505;
int id[N][N],n,cnt;
int fa[M],fav[M];
int sz[M],val[M];
bool query(int x1,int y1,int x2,int y2){
	assert(1<=x1&&x1<=x2&&x2<=n&&1<=y1&&y1<=y2&&y2<=n);
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	scanf("%d",&x1);
	return x1==1;
}
int get(int x){
	if (x==fa[x]) return x;
	int tmp=get(fa[x]);
	val[x]=val[fa[x]]^fav[x];
	return tmp;
}
void merge(int x1,int y1,int x2,int y2){
	int id1=id[x1][y1];
	int id2=id[x2][y2];
	int fid1=get(id1);
	int fid2=get(id2);
	if (fid1==fid2) return;
	int res=query(x1,y1,x2,y2)^1;
	res^=val[id1]^val[id2];
	if (sz[fid1]<sz[fid2]) swap(fid1,fid2);
	fav[fid2]=res; fa[fid2]=fid1; sz[fid1]+=sz[fid2];
}
int main(){
	scanf("%d",&n);
	For(i,1,n) For(j,1,n) id[i][j]=++cnt;
	For(i,1,cnt) fa[i]=i,sz[i]=1;
	For(i,3,n) For(j,1,n) merge(i-2,j,i,j);
	For(i,1,n) For(j,3,n) merge(i,j-2,i,j);
	For(i,2,n) For(j,2,n) merge(i-1,j-1,i,j);
	For(i,2,n-1) For(j,2,n){
		For(di,-1,1) For(dj,-1,0) get(id[i+di][j+dj]);
		if (val[id[i-1][j]]!=val[id[i][j-1]]||val[id[i][j]]!=val[id[i+1][j-1]]) merge(i-1,j-1,i+1,j);
		else if ((val[id[i-1][j-1]]==val[id[i+1][j-1]])==(val[id[i-1][j]]==val[id[i+1][j]])) merge(i-1,j-1,i+1,j);
	}
	printf("!\n");
	For(i,1,n) For(j,1,n){
		get(id[i][j]);
		get(id[n][n]);
		putchar(val[id[i][j]]==val[id[n][n]]?'0':'1');
		if (j==n) puts("");
	}
	fflush(stdout);
	return 0;
}