#include <bits/stdc++.h>
using namespace std;
const int N=2050;
char col[N][N];
int sum[N][N];
void Add(int x1,int x2,int y1,int y2){
	x1=max(x1,1);y1=max(y1,1);
	if(x1>x2 || y1>y2)return;
	sum[x1][y1]++;
	sum[x2+1][y1]--;
	sum[x1][y2+1]--;
	sum[x2+1][y2+1]++;
}
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	for(int i=1;i<=n;i++)scanf("%s",col[i]+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int mn=-1,mx=-1;
		for(int j=1;j<=n;j++)
			if(col[i][j]=='B')
				mx=j,mn=mn==-1?j:mn;
		if(mx==-1)ans++;
		else Add(i-k+1,i,mx-k+1,mn);
	}
	for(int j=1;j<=n;j++){
		int mn=-1,mx=-1;
		for(int i=1;i<=n;i++)
			if(col[i][j]=='B')
				mx=i,mn=mn==-1?i:mn;
		if(mx==-1)ans++;
		else Add(mx-k+1,mn,j-k+1,j);
	}
	int mx=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1],
			mx=max(mx,sum[i][j]);
	printf("%i\n",mx+ans);
	return 0;
}