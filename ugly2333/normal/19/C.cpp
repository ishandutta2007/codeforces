//CF 19C
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
const int N = 111111;
int n,a[N],m,p[N];
map<int,int> M;
int b[N][12],c[N];
bool chk(int i,int j){
	int t;
	t=j;
	while(j<=n&&a[i]==a[j]){
		i++;
		j++;
		if(i==t)
			return 1;
	}
	return 0;
}
int main()
{
	int i,j,x,ans,f;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		x=a[i];
		if(M.find(x)==M.end())
			M[x]=++m;
		x=M[x];
		c[i]=++p[x];
		b[x][c[i]]=i;
	}
	ans=1,i=1;
	while(i<=n){
		x=M[a[i]];
		for(j=c[i]+1;j<=p[x];j=j+1){
			if(chk(i,b[x][j])){
				ans=b[x][j];
				i=b[x][j]-1;
			}
		}
		i++;
	}
	cout<<n-ans+1<<endl;
	for(i=ans;i<=n;i=i+1)
		printf("%d ",a[i]);//cout<<a[i]<<' ';
	return 0;
}