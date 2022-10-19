#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
int n,ans[N],tr[30],mx;
int query(int l,int r)
{
	int ans=0;
	for(int i=l;i<=r;i++)
		ans=max(ans,tr[i]);
	return ans;
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		ans[i]=query(s[i]-'a'+1,26)+1;
		mx=max(mx,ans[i]);
		tr[s[i]-'a']=max(tr[s[i]-'a'],ans[i]);
	}
	printf("%d\n",mx);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}