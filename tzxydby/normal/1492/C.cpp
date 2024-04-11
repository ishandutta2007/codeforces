#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,pl[N],pr[N],ans;
char s[N],t[N];
int main()
{
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	pl[0]=0;
	for(int i=1;i<=n;i++)
	{
		pl[i]=pl[i-1];
		if(s[i]==t[pl[i]+1])
			pl[i]++;
	}
	pr[n+1]=m+1;
	for(int i=n;i>=1;i--)
	{
		pr[i]=pr[i+1];
		if(s[i]==t[pr[i]-1])
			pr[i]--;
	}
	int l=1,r=1;
	while(!pl[l])
		l++,r++;
	for(;l<n;l++)
	{
		while(r<=n&&pl[l]+1>=pr[r])
			r++;
		ans=max(ans,r-1-l);
	}
	printf("%d\n",ans);
	return 0;
}