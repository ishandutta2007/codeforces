//CF 787C
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
const int N = 7777;
string c[3];
int n,a[N][2],ans[N][2],vis[N][2],cnt[N][2];
queue<int> Q,R;
int main()
{
	c[0]="Lose ",c[1]="Loop ",c[2]="Win ";
	int i,j,k,l,s[2],x;
	scanf("%d",&n);
	for(j=0;j<=1;j=j+1){
		scanf("%d",s+j);
		for(i=1;i<=s[j];i=i+1){
			scanf("%d",&x);
			a[x][j]=1;
		}
	}
	Q.push(0),vis[0][0]=1;
	Q.push(N),vis[0][1]=1;
	for(l=1;l<=n;l=l+1){
		while(!Q.empty()){
			x=Q.front(),Q.pop();
			i=x%N,j=x/N;
			ans[i][j]=-1;
			j^=1;
			for(k=1;k<n;k=k+1){
				if(!a[k][j])
					continue;
				x=(i-k+n)%n;
				if(!vis[x][j])
					R.push(x+N*j),vis[x][j]=1;
			}
		}
		
		while(!R.empty()){
			x=R.front(),R.pop();
			i=x%N,j=x/N;
			ans[i][j]=1;
			j^=1;
			for(k=1;k<n;k=k+1){
				if(!a[k][j])
					continue;
				x=(i-k+n)%n;
				if(!vis[x][j])
					cnt[x][j]++;
			}
		}
		
		for(i=1;i<n;i=i+1)
			for(j=0;j<=1;j=j+1)
				if(!vis[i][j]&&cnt[i][j]==s[j])
					Q.push(i+N*j),vis[i][j]=1;
	}
	for(j=0;j<=1;j=j+1){
		for(i=1;i<n;i=i+1)
			cout<<c[ans[i][j]+1];
		cout<<endl;
	}
	return 0;
}