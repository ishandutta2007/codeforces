#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
const int N=5e3+5;
int id[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(id,0,sizeof(id));
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if(id[x]&&id[x]<i-1) flag=true;
			if(!id[x]) id[x]=i;
		}
		printf(flag?"YES\n":"NO\n");
	}
	return 0;
}