//CF1098B
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
const int N = 333333;
int W(char c){
	if(c=='A')
		return 0;
	if(c=='C')
		return 1;
	if(c=='G')
		return 2;
	if(c=='T')
		return 3;
}
int n,m,a[N][2][4],b[N][2][4];
char c[N],d[4]={'A','C','G','T'};
string p[2];
int main()
{
	int i,j,o,x,y,z,w,s,sx,sy,ss;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i=i+1){
		scanf("%s",c);
		for(j=0;j<m;j=j+1){
			o=W(c[j]);
			a[i][j&1][o]++;
			b[j][i&1][o]++;
		}
	}
	s=-1;
	for(x=0;x<4;x=x+1){
		for(y=x+1;y<4;y=y+1){
			for(z=0;z==x||z==y;z++);
			for(w=3;w==x||w==y;w--);
			o=0;
			for(i=0;i<n;i=i+1){
				if(i&1)
					o+=max(a[i][0][w]+a[i][1][z],a[i][0][z]+a[i][1][w]);
				else
					o+=max(a[i][0][x]+a[i][1][y],a[i][0][y]+a[i][1][x]);
			}
			if(s<o)
				s=o,sx=x,sy=y,ss=1;
			o=0;
			for(i=0;i<m;i=i+1){
				if(i&1)
					o+=max(b[i][0][w]+b[i][1][z],b[i][0][z]+b[i][1][w]);
				else
					o+=max(b[i][0][x]+b[i][1][y],b[i][0][y]+b[i][1][x]);
			}
			if(s<o)
				s=o,sx=x,sy=y,ss=2;
		}
	}
	if(ss==2){
		x=sx,y=sy;
		for(z=0;z==x||z==y;z++);
		for(w=3;w==x||w==y;w--);
		for(i=0;i<m;i=i+1){
			if(i&1){
				if(b[i][0][w]+b[i][1][z]>b[i][0][z]+b[i][1][w])
					p[0]+=d[w],p[1]+=d[z];
				else
					p[0]+=d[z],p[1]+=d[w];
			}
			else{
				if(b[i][0][x]+b[i][1][y]>b[i][0][y]+b[i][1][x])
					p[0]+=d[x],p[1]+=d[y];
				else
					p[0]+=d[y],p[1]+=d[x];
			}
		}
		for(i=0;i<n;i=i+1)
			cout<<p[i&1]<<endl;
	}
	else{
		x=sx,y=sy;
		for(z=0;z==x||z==y;z++);
		for(w=3;w==x||w==y;w--);
		for(i=0;i<n;i=i+1){
			if(i&1){
				if(a[i][0][w]+a[i][1][z]>a[i][0][z]+a[i][1][w])
					c[0]=d[w],c[1]=d[z];
				else
					c[0]=d[z],c[1]=d[w];
			}
			else{
				if(a[i][0][x]+a[i][1][y]>a[i][0][y]+a[i][1][x])
					c[0]=d[x],c[1]=d[y];
				else
					c[0]=d[y],c[1]=d[x];
			}
			for(j=0;j<m;j=j+1)
				cout<<c[j&1];
			cout<<endl;
		}
	}
	return 0;
}