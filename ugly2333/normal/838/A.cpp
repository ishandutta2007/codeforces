//CF 838A
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
int a[2555][2555];
int main()
{
	char ch[2555];
	int n,m,i,j,k,ans,s,p;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%s",ch+1);
		for(j=1;j<=m;j=j+1){
			a[i][j]=ch[j]-'0';
			a[i][j]+=a[i][j-1];
		}
		for(j=1;j<=m;j=j+1)
			a[i][j]+=a[i-1][j];
	}
	ans=n*m;
	for(k=2;k<=max(n,m);k=k+1){
		s=0;
		for(i=k;i<n+k;i=i+k)
			for(j=k;j<m+k;j=j+k){
				p=a[min(n,i)][min(m,j)]+a[i-k][j-k];
				p-=a[min(n,i)][j-k]+a[i-k][min(m,j)];
				s+=min(p,k*k-p);
				//cout<<p<<' ';
			}
		ans=min(ans,s);
		//cout<<k<<s<<endl;
	}
	printf("%d",ans);
	return 0;
}