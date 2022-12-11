#include<bits/stdc++.h>
#define maxn 3000005
using namespace std;
int n,k;
char s[maxn],ss[maxn];
vector<int> Ans[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int l=1,r=n;
	for(int i=1;i<=n;++i)if(s[i]=='L')l++;else break;
	for(int i=n;i>=1;--i)if(s[i]=='R')r--;else break;
	int ll=l,rr=r;
	for(int i=1;i<=n;++i)ss[i]=s[i];
	if(l>r)
	{
		puts("-1");
		return 0;
	}
	int mn=0,mx=0,T=1;
	for(;;++T)
	{
		vector<int> kt;kt.clear(); 
		for(int i=l;i<r;++i)if(s[i]=='R'&&s[i+1]=='L')
		{
			Ans[T].push_back(i);
			mx++;
		}
		for(int x:Ans[T])swap(s[x],s[x+1]);
		mn++;
		for(int i=l;i<=r;++i)if(s[i]=='L')l++;else break;
		for(int i=r;i>=l;--i)if(s[i]=='R')r--;else break;
		if(l>r)break;
	}
	if(mn<=k&&k<=mx)
	{
		int t=k-mn;
		for(int i=1;i<=T;++i)
		{
			vector<int> tmp;
			tmp.clear();
			for(int x:Ans[i])
			{
				if(t>0)printf("%d %d\n",1,x),t--;
				else tmp.push_back(x);
			}
			if(tmp.size()>0)
			{
				printf("%d",tmp.size());
				for(int x:tmp)printf(" %d",x);
				puts("");
			}
			else t++;
		}
	}
	else puts("-1");
}