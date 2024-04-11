#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int L=9;
int rmq[N][N][L][L];
int mx[N][N];
char s[N][N];
int sum[4][N][N],n,m,lgs[N];
bool All(int k,int x1,int y1,int x2,int y2){return sum[k][x2][y2]-sum[k][x1-1][y2]-sum[k][x2][y1-1]+sum[k][x1-1][y1-1]==(x2-x1+1)*(y2-y1+1);}
bool Check(int x,int y,int sz){
	if(sz>min({x,y,n-x,m-y}))return 0;
	if(All(0,x-sz+1,y-sz+1,x,y)
	&& All(1,x-sz+1,y+1,x,y+sz)
	&& All(2,x+1,y-sz+1,x+sz,y)
	&& All(3,x+1,y+1,x+sz,y+sz))return 1;
	return 0;
}
int MX(int x1,int x2,int y1,int y2){
	if(x1>x2 || y1>y2)return 0;
	int i=lgs[x2-x1+1];
	int j=lgs[y2-y1+1];
	//printf("%i %i:%i %i %i %i\n",i,j,rmq[x1][y1][i][j],rmq[x2-(1<<i)+1][y1][i][j],rmq[x1][y2-(1<<j)+1][i][j],rmq[x2-(1<<i)+1][y2-(1<<j)+1][i][j]);
	return max({rmq[x1][y1][i][j],rmq[x2-(1<<i)+1][y1][i][j],rmq[x1][y2-(1<<j)+1][i][j],rmq[x2-(1<<i)+1][y2-(1<<j)+1][i][j]});
}
int main(){
	map<char,int> idx;
	idx['R']=0;
	idx['G']=1;
	idx['Y']=2;
	idx['B']=3;
	int q;
	scanf("%i %i %i",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			for(int k=0;k<4;k++)
				sum[k][i][j]=sum[k][i-1][j]+sum[k][i][j-1]-sum[k][i-1][j-1];
			sum[idx[s[i][j]]][i][j]++;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)while(Check(i,j,mx[i][j]+1))mx[i][j]++;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)rmq[i][j][0][0]=mx[i][j];//,printf("%i%c",mx[i][j],j==m?'\n':' ');
	for(int i=0;i<L;i++)
		for(int j=0;j<L;j++)if(i+j!=0)
			for(int x=1;x<=n-(1<<i)+1;x++)
				for(int y=1;y<=m-(1<<j)+1;y++){
					if(i)rmq[x][y][i][j]=max(rmq[x][y][i-1][j],rmq[x+(1<<i-1)][y][i-1][j]);
					else rmq[x][y][i][j]=max(rmq[x][y][i][j-1],rmq[x][y+(1<<j-1)][i][j-1]);
					//if(rmq[x][y][i][j])printf(":D %i %i %i %i\n",x,y,x+(1<<i)-1,y+(1<<j)-1);
				}
	for(int i=2;i<N;i++)lgs[i]=lgs[i>>1]+1;
	for(int i=1;i<=q;i++){
		int x1,y1,x2,y2;
		scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
		int top=N,bot=1,mid,ans=0;
		while(top>=bot){
			mid=top+bot>>1;
			if(MX(x1+mid-1,x2-mid,y1+mid-1,y2-mid)>=mid)ans=mid,bot=mid+1;
			else top=mid-1;
		}
		printf("%i\n",ans*ans*4);
	}
	//printf("%i\n",MX(1,4,1,4));
	return 0;
}