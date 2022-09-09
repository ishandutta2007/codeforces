#include <bits/stdc++.h>
using namespace std;
int mn[8];
const int inf=1e7+7;
int main()
{
	int n,i,x;for(i=1;i<8;i++) mn[i]=inf;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i",&x);
		string s;cin >> s;
		int y=0;
		for(i=0;i<s.size();i++) y|=1<<(s[i]-'A');
		mn[y]=min(mn[y],x);
	}
	int sol=inf;
	for(int mask=1;mask<1<<8;mask++)
	{
		int Or=0,sum=0;
		for(i=0;i<8;i++) if((mask>>i)&1) sum+=mn[i],Or|=i;
		if(Or==7) sol=min(sol,sum);
	}
	if(sol==inf) printf("-1\n");
	else printf("%i\n",sol);
	return 0;
}