#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N=1e5+5;
int cnt[N];
char s[3];
int main()
{
	int n;
	scanf("%d",&n);
	int tot1=0,tot2=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
		if(cnt[x]%2==0) tot1++;
		if(cnt[x]==4) tot2++;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%s%d",s,&x);
		if(s[0]=='+')
		{
			cnt[x]++;
			if(cnt[x]%2==0) tot1++;
			if(cnt[x]==4) tot2++;
		}
		else
		{
			cnt[x]--;
			if(cnt[x]%2==1) tot1--;
			if(cnt[x]==3) tot2--;
		}
		if(tot1>=4&&tot2>=1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}