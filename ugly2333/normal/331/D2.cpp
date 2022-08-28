//CF 331D2
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 1005;
int dx[5]={0,1,0,-1,0};// 0 1 2 3 4
int dy[5]={0,0,1,0,-1};// - R U L D
int n,b,q;
int a[N+5][N+5];
int nx[N*N*5+55][2];
int ans[111111];
LL t[111111];
int hash1(int x,int y,int d){
	if(a[x][y])
		d=a[x][y];
	return d*N*N+x*N+y;
}
int main()
{
	int i,j,k,x1,y1,x2,y2,d,h;
	char ch[5];
	scanf("%d%d",&n,&b);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2){
			if(y1>y2)
				d=4;
			else
				d=2;
		}
		else{
			if(x1>x2)
				d=3;
			else
				d=1;
		}
		//cout<<dx[d]<<dy[d];
		while(x1!=x2||y1!=y2){
			a[x1][y1]=d;
			x1+=dx[d];
			y1+=dy[d];
			//cout<<x1<<y1<<endl;
		}
		a[x2][y2]=d;
	}
	for(i=0;i<=b;i=i+1)
		for(j=0;j<=b;j=j+1)
			for(k=1;k<=4;k=k+1){
				if(a[i][j]&&a[i][j]!=k)
					continue;
				h=hash1(i,j,k);
				x1=i+dx[k];
				y1=j+dy[k];
				if(x1<0||x1>b||y1<0||y1>b)
					nx[h][0]=h;
				else
					nx[h][0]=hash1(x1,y1,k);
			}
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d%d%s%lld",&x1,&x2,&ch,t+i);
		if(ch[0]=='R')
			d=1;
		if(ch[0]=='U')
			d=2;
		if(ch[0]=='L')
			d=3;
		if(ch[0]=='D')
			d=4;
		ans[i]=hash1(x1,x2,d);
	}
	for(i=0;i<=60;i=i+1){
		h=i&1;
		for(j=1;j<=q;j=j+1)
			if(t[j]&((LL)1<<i))
				ans[j]=nx[ans[j]][h];
		for(j=1;j<N*N*5;j=j+1)
			nx[j][h^1]=nx[nx[j][h]][h];
	}
	for(i=1;i<=q;i=i+1){
		y1=ans[i]%N;
		ans[i]/=N;
		x1=ans[i]%N;
		cout<<x1<<' '<<y1<<endl;
	}
	return 0;
}