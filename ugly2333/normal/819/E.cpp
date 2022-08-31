// CF 819E
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
int p[111111][5],ans;
void sp(int n,int a,int b,int c,int d,int t){
	while(t--){
		ans++;
		p[ans][0]=n;
		p[ans][1]=a;
		p[ans][2]=b;
		p[ans][3]=c;
		p[ans][4]=d;
	}
}
int main()
{
	int n,i,j,x,y;
	scanf("%d",&n);
	ans=0;
	if(n%2==1){
		for(i=3;i<=n;i=i+2){
			x=i-1;
			y=i;
			sp(3,1,x,y,0,2);
			for(j=2;j<=i-2;j=j+2)
				sp(4,j,x,j+1,y,2);
		}
	}
	else{
		sp(3,1,2,3,0,1);
		sp(3,1,2,4,0,1);
		sp(3,1,3,4,0,1);
		sp(3,2,3,4,0,1);
		for(i=6;i<=n;i=i+2){
			x=i-1;
			y=i;
			sp(3,1,x,y,0,1);
			sp(3,2,x,y,0,1);
			sp(4,1,x,2,y,1);
			for(j=3;j<=i-2;j=j+2)
				sp(4,j,x,j+1,y,2);
		}
	}
	printf("%d\n",ans);
	for(i=1;i<=ans;i=i+1){
		printf("%d",p[i][0]);
		for(j=1;j<=p[i][0];j=j+1)
			printf(" %d",p[i][j]);
		printf("\n");
	}
	return 0;
}