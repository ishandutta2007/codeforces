#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=100+5,inf=1e9,mx1=1e6+5;
char s[mx];
int M[mx][mx],p[mx1];
vector<int> ans;
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)
		{
			if(s[j]=='1') M[i][j]=1;
			else if(i==j) M[i][j]=0;
			else M[i][j]=inf;
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",p+i);
	ans.push_back(p[1]);
	for(int i=2;i<m;i++)
		if(M[ans[ans.size()-1]][p[i+1]]<M[ans[ans.size()-1]][p[i]]+M[p[i]][p[i+1]])
			ans.push_back(p[i]);
	ans.push_back(p[m]);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}