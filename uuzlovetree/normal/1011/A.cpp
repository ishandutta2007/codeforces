#include<bits/stdc++.h>
#define ll long long
#define maxn 55
using namespace std;
int n,k;
char s[maxn];
int w[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)w[s[i]-'a'+1]++;
	int last=-1,tot=0,ans=0;
	for(int i=1;i<=26;++i)if(w[i]&&i-last>1)
	{
		tot++;ans+=i;last=i;
		if(tot==k)break;
	}
	if(tot<k)puts("-1");else printf("%d\n",ans);
	return 0;
}