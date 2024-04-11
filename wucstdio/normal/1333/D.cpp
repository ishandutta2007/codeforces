#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,k,pre[3005],suf[3005];
char s[3005];
bool flag[3005];
vector<int>x;
pair<int,int>calc()
{
	int ans=0,num=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='L'&&s[i-1]=='R'&&!flag[i-1])
		{
			flag[i-1]=1;
			x.push_back(i-1);
		}
		if(s[i]=='R')num++;
		else ans+=num;
	}
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(s[i]=='R');
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+(s[i]=='L');
	int maxx=0;
	for(int i=1;i<n;i++)
	{
		if(pre[i]&&suf[i+1])
		  maxx=max(maxx,pre[i]+suf[i+1]);
	}
	return make_pair(max(0,maxx-1),ans);
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	pair<int,int>now=calc();
	if(k<now.first||k>now.second)
	{
		printf("-1\n");
		return 0;
	}
	while(k>n)
	{
		k--;
		int p=x.back();
		x.pop_back();
		swap(s[p],s[p+1]);
		flag[p]=0;
		printf("1 %d\n",p);
		if(s[p-1]=='R'&&s[p]=='L'&&!flag[p-1])
		{
			flag[p-1]=1;
			x.push_back(p-1);
		}
		if(s[p+1]=='R'&&s[p+2]=='L'&&!flag[p+1])
		{
			flag[p+1]=1;
			x.push_back(p+1);
		}
	}
	while(k>calc().first)
	{
		k--;
		int p=x.back();
		x.pop_back();
		swap(s[p],s[p+1]);
		flag[p]=0;
		printf("1 %d\n",p);
		if(s[p-1]=='R'&&s[p]=='L'&&!flag[p-1])
		{
			flag[p-1]=1;
			x.push_back(p-1);
		}
		if(s[p+1]=='R'&&s[p+2]=='L'&&!flag[p+1])
		{
			flag[p+1]=1;
			x.push_back(p+1);
		}
	}
	while(calc().first)
	{
		printf("%d ",(int)x.size());
		for(auto i:x)
		{
			swap(s[i],s[i+1]);
			flag[i]=0;
			printf("%d ",i);
		}
		printf("\n");
		x.clear();
	}
	return 0;
}