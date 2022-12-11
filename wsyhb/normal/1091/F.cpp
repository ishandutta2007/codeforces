#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
long long l[max_n];
char s[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",l+i);
	scanf("%s",s+1);
	long long S=0,G=0,T=0;
	// S: current stamina
	// G: 2 * current length of walking (that can be turned into flying)
	// double S to avoid 0.5
	// T: current time used (answer)
	bool vis_w=false;
	// vis_w: whether to have visited water
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='G')
		{
			S+=l[i];
			G+=2*l[i];
			T+=5*l[i];
		}
		else if(s[i]=='W')
		{
			S+=l[i];
			T+=3*l[i];
			vis_w=true;
		}
		else // the most important case: lava
		{
			S-=l[i];
			T+=l[i];
			if(S<0)
			{
				if(vis_w)
					T+=3*(-S);
				else
					T+=5*(-S);
				S=0;
			}
		}
		G=min(G,S);
	}
	if(S>0)
	{
		T-=2*G;
		T-=S-G;
	}
	printf("%lld\n",T);
	return 0;
}