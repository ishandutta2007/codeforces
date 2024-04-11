//CF1439A
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
const int N = 111;
char s[N][N];
int n,m,a[N][N],b[N][N];
vector<int> v[6];
void go(int a1,int b1,int a2,int b2,int a3,int b3){
	a[a1][b1]^=1,a[a2][b2]^=1,a[a3][b3]^=1;
	v[0].push_back(a1);
	v[1].push_back(b1);
	v[2].push_back(a2);
	v[3].push_back(b2);
	v[4].push_back(a3);
	v[5].push_back(b3);
}
int main()
{
	int T,i,j,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i=i+1){
			scanf("%s",s[i]+1);
			for(j=1;j<=m;j=j+1)
				a[i][j]=s[i][j]-'0';
		}
		for(i=1;i<=n-2;i=i+1){
			for(j=1;j<=m;j=j+1){
				if(a[i][j]){
					if(j==1)
						go(i,j,i+1,j,i+1,j+1);
					else
						go(i,j,i+1,j,i+1,j-1);
				}
			}
		}
		for(j=1;j<=m-2;j=j+1){
			if(a[n-1][j]&&a[n][j])
				go(n-1,j,n,j,n,j+1);
			if(a[n-1][j])
				go(n-1,j,n-1,j+1,n,j+1);
			if(a[n][j])
				go(n,j,n-1,j+1,n,j+1);
		}
		x=0;
		for(i=n-1;i<=n;i=i+1){
			for(j=m-1;j<=m;j=j+1){
				if(a[i][j])
					b[i][j]=1,x^=1;
				else
					b[i][j]=0;
			}
		}
		for(i=n-1;i<=n;i=i+1){
			for(j=m-1;j<=m;j=j+1){
				if(b[i][j]^x)
					go(n*2-1-i,j,i,m*2-1-j,n*2-1-i,m*2-1-j);
			}
		}
		cout<<v[0].size()<<endl;
		for(i=0;i<v[0].size();i=i+1){
			for(j=0;j<6;j=j+1)
				cout<<v[j][i]<<' ';
			cout<<endl;
		}
		for(j=0;j<6;j=j+1)
			v[j].clear();
	}
	return 0;
}