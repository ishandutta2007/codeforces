#include <bits/stdc++.h>
using namespace std;

const int MN = 110;
int w,h,n,ans[MN],ansc, arr[MN][MN][2],v[MN][MN],x,y,a,b,i,j,ii,jj;

int main(){
	scanf("%d%d%d",&w,&h,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if(x==a)for(j=y;j<b;j++)arr[x-1][j][0]=1;
		else for(j=x;j<a;j++)arr[j][y-1][1]=1;
	}
	for(i=0;i<h;i++)arr[w-1][i][0]=1;
	for(i=0;i<w;i++)arr[i][h-1][1]=1;
	for(i=0;i<w;i++)for(j=0;j<h;j++)if(v[i][j]==0){
		x=a=i; y=b=j;
		while(arr[a][y][0]==0) a++;
		while(arr[x][b][1]==0) b++;
		ans[ansc++]=(a-x+1)*(b-y+1);
		for(ii=x;ii<=a;ii++)for(jj=y;jj<=b;jj++)v[ii][jj]=1;
		j=b;
	}
	sort(ans,ans+ansc);
	for(int i=0;i<ansc;i++)printf("%d ",ans[i]);
	return 0;
}