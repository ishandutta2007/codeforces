#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,k;
int a[maxn];
vector<int> Ans;
int main()
{
	scanf("%d%d",&n,&k);
	int s=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if(s%k)
	{
		puts("No");
		return 0;
	}
	int t=s/k,cnt=0;
	for(int i=1;i<=n;++i)
	{
		t-=a[i];
		++cnt;
		if(t==0)
		{
			Ans.push_back(cnt);
			cnt=0;
			t=s/k;
		}
		if(t<0)
		{
			puts("No");
			return 0;
		}
	}
	if(t!=s/k)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=0;i<Ans.size();++i)printf("%d ",Ans[i]);
	return 0;
}