//CF1090E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 11;
int dx[8]={2,2,1,1,-1,-1,-2,-2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};
int n=8,k,a[N][N],b[N][N],f[N][N];
char ch[N];
vector<int> v[4];
void sv(int x,int y,int z,int w){
	v[0].push_back(x);
	v[1].push_back(y);
	v[2].push_back(z);
	v[3].push_back(w);
	a[x][y]=0;
	a[z][w]=1;
}
void mv(int cx,int cy,int x,int y){
	if(cx==x&&cy==y)
		return;
	int i=f[cx][cy];
	mv(i/N,i%N,x,y);
	sv(i/N,i%N,cx,cy);
}
queue<int> q;
void go(int sx,int sy,int tx,int ty){
	int i,x,y,xx,yy;
	memset(f,0,sizeof(f));
	q.push(sx*N+sy);
	while(!q.empty()){
		xx=q.front()/N;
		yy=q.front()%N;
		q.pop();
		for(i=0;i<8;i=i+1){
			x=xx+dx[i],y=yy+dy[i];
			if(x>0&&x<=n&&y>0&&y<=n&&!f[x][y]){
				f[x][y]=xx*N+yy;
				q.push(x*N+y);
			}
		}
	}
	while(sx!=tx||sy!=ty){
		for(x=tx,y=ty;!a[x][y];){
			i=f[x][y];
			x=i/N,y=i%N;
		}
		mv(tx,ty,x,y);
		tx=x,ty=y;
	}
}
int main()
{
	int i,j,x,y,z,f;
	cin>>k;
	for(i=1;i<=k;i=i+1){
		cin>>ch;
		a[ch[1]-'0'][ch[0]-'a'+1]=1;
	}
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			if(k)
				b[i][j]=1,k--;
	while(1){
		f=0;
		for(i=1;i<=n;i=i+1)
			for(j=1;j<=n;j=j+1)
				for(x=1;x<=n;x=x+1)
					for(y=1;y<=n;y=y+1)
						if(a[i][j]&&!b[i][j])
							if(b[x][y]&&!a[x][y])
								go(i,j,x,y),f=1;
		if(!f)
			break;
	}
	z=v[0].size();
	cout<<z<<endl;
	for(i=0;i<z;i=i+1){
		ch[1]=v[0][i]+'0';
		ch[0]=v[1][i]+'a'-1;
		ch[4]=v[2][i]+'0';
		ch[3]=v[3][i]+'a'-1;
		ch[2]='-';
		cout<<ch<<endl;
	}
	return 0;
}