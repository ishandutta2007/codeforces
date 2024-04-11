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
int a,b,m,ans[N*N];
int id[N][N],e[N][N];
int mat[2][N][N],res;
void extend(int x,int y,int cx,int cy,int fl){
	//cout<<x<<' '<<y<<' '<<cx<<' '<<cy<<' '<<fl<<endl; 
	mat[fl][x][cy]=0;
	mat[fl^1][y][cy]=0;
	if (mat[fl^1][y][cx])
		extend(y,mat[fl^1][y][cx],cy,cx,fl^1);
	mat[fl^1][y][cx]=x;
	mat[fl][x][cx]=y;
	fl?e[y][x]=cx:e[x][y]=cx;
}
int main(){
	scanf("%d%d%d",&a,&b,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		id[x][y]=i;
		int cx=1,cy=1;
		for (;mat[0][x][cx];++cx);
		for (;mat[1][y][cy];++cy);
		//cout<<"COL "<<cx<<' '<<cy<<endl;
		res=max(res,max(cx,cy));
		if (mat[1][y][cx]) extend(y,mat[1][y][cx],cy,cx,1);
		mat[0][x][cx]=y;
		mat[1][y][cx]=x;
		e[x][y]=cx;
		/*For(j,1,a) For(k,1,b)
			if (e[j][k]){
				printf("%d %d %d %d %d\n",j,k,e[j][k],mat[0][j][e[j][k]],mat[1][k][e[j][k]]);
				assert(mat[0][j][e[j][k]]==k);
				assert(mat[1][k][e[j][k]]==j);
			}*/
	}
	For(i,1,a) For(j,1,b)
		ans[id[i][j]]=e[i][j];
	printf("%d\n",res);
	For(i,1,m) printf("%d ",ans[i]);
}