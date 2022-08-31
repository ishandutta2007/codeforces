//CF 842D
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
const int N = 2*333333;
int a[N*4],cur;
bool st[N+333][30];
int main()
{
	int n,m,i,j,k,x,y,z,t,ans;
	scanf("%d%d",&n,&m);
	memset(st,0,sizeof(st));
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		st[a[i]][0]=1;
	}
	for(j=1;j<=20;j=j+1){
		for(i=0;i+(1<<j)<=N;i=i+1)
			st[i][j]=st[i][j-1]&st[i+(1<<(j-1))][j-1];
	}
	cur=0;
	while(m--){
		scanf("%d",&k);
		cur^=k;
		x=0;
		z=1<<20;
		ans=0;
		for(j=19;j>=0;j=j-1){
			t=(cur>>j)&1;
			y=(x+z)>>1;
			//cout<<t<<' '<<x<<' '<<y<<' '<<z<<endl;
			if(t){
				if(st[y][j]){
					z=y;
					ans+=(1<<j);
				}
				else
					x=y;
			}
			else{
				if(st[x][j]){
					x=y;
					ans+=(1<<j);
				}
				else
					z=y;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}