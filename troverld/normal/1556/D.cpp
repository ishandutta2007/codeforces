#include<bits/stdc++.h>
using namespace std;
int n,m,o[4][4],a[4][4],b[10100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=3;i++)for(int j=i+1;j<=3;j++){
		printf("and %d %d\n",i,j),fflush(stdout);
		scanf("%d",&a[i][j]); 
		printf("or %d %d\n",i,j),fflush(stdout);
		scanf("%d",&o[i][j]); 
	}
	for(int i=0;i<=30;i++){
		for(int u=0;u<=1;u++)for(int v=0;v<=1;v++)for(int w=0;w<=1;w++){
			if((u&v)!=((a[1][2]>>i)&1))continue;
			if((v&w)!=((a[2][3]>>i)&1))continue;
			if((w&u)!=((a[1][3]>>i)&1))continue;
			if((u|v)!=((o[1][2]>>i)&1))continue;
			if((v|w)!=((o[2][3]>>i)&1))continue;
			if((w|u)!=((o[1][3]>>i)&1))continue;
			b[1]|=(u<<i);
			b[2]|=(v<<i);
			b[3]|=(w<<i);
//			printf("%d:%d,%d,%d\n",i,u,v,w);
		}
	}
	for(int i=4,x,y;i<=n;i++){
		printf("and %d %d\n",1,i),fflush(stdout);
		scanf("%d",&x);
		printf("or %d %d\n",1,i),fflush(stdout);
		scanf("%d",&y);
		b[i]=(y-x)^b[1];
	}
//	for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
	sort(b+1,b+n+1);
	printf("finish %d\n",b[m]);fflush(stdout);
	return 0;
}
/*
3 1
0
7
0
5
4
6
*/