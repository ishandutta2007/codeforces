#include<bits/stdc++.h>
#define maxn 400005
using namespace std;
int n;
int a[maxn];
char str[maxn][5];
vector<int> g[4],b;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",str[i]);
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		if(str[i][0]=='0'&&str[i][1]=='0')g[0].push_back(a[i]);
		if(str[i][0]=='0'&&str[i][1]=='1')g[1].push_back(a[i]);
		if(str[i][0]=='1'&&str[i][1]=='0')g[2].push_back(a[i]);
		if(str[i][0]=='1'&&str[i][1]=='1')g[3].push_back(a[i]);
	}
	for(int i=0;i<4;++i)sort(g[i].begin(),g[i].end(),cmp);
	int ans=0;
	int sz=min(g[1].size(),g[2].size());
	for(int i=0;i<sz;++i)ans+=g[1][i]+g[2][i];
	for(int i=sz;i<g[1].size();++i)b.push_back(g[1][i]);
	for(int i=sz;i<g[2].size();++i)b.push_back(g[2][i]);
	for(int i=0;i<g[3].size();++i)ans+=g[3][i];
	int k=g[3].size();
	for(int i=0;i<g[0].size();++i)b.push_back(g[0][i]);
	sort(b.begin(),b.end(),cmp);
	int bsz=b.size();
	for(int i=0;i<min(k,bsz);++i)ans+=b[i];
	cout<<ans<<endl;
	return 0;
}