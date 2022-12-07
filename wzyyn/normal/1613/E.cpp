#include<bits/stdc++.h>

using namespace std;

const int N=1000005;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m,sx,sy;
char s[N];
int mp[N],d[N];
int inq[N],q[N];
int ID(int x,int y){
	return (x-1)*m+y;
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++){
			if (s[j]=='.') mp[ID(i,j)]=0;
			if (s[j]=='#') mp[ID(i,j)]=1;
			if (s[j]=='L'){
				mp[ID(i,j)]=2;
				sx=i; sy=j;
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (mp[ID(i,j)]!=1){
				d[ID(i,j)]=0;
				for (int p=0;p<4;p++){
					int ni=i+dx[p],nj=j+dy[p];
					if (ni<1||ni>n||nj<1||nj>m) continue;
					if (mp[ID(ni,nj)]!=1)
						++d[ID(i,j)];
				}
			}
	for (int i=1;i<=n*m;i++)
		inq[i]=0;
	int h=0,t=1;
	q[1]=ID(sx,sy);
	inq[ID(sx,sy)]=1;
	while (h!=t){
		int id=q[++h];
		int y=(id-1)%m+1,x=(id-y)/m+1;
		for (int p=0;p<4;p++){
			int nx=x+dx[p],ny=y+dy[p];
			if (nx<1||nx>n||ny<1||ny>m) continue;
			if (mp[ID(nx,ny)]!=1&&!inq[ID(nx,ny)])
				if ((--d[ID(nx,ny)])<=1){
					inq[ID(nx,ny)]=1;
					mp[ID(nx,ny)]=3;
					q[++t]=ID(nx,ny);
				}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (mp[ID(i,j)]==0) putchar('.');
			if (mp[ID(i,j)]==1) putchar('#');
			if (mp[ID(i,j)]==2) putchar('L');
			if (mp[ID(i,j)]==3) putchar('+');
		}
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}