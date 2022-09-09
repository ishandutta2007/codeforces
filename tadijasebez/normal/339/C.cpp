#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=15;
const int M=1050;
map<int,bool> dp[M][N];
map<int,int> go[M][N];
vector<int> w;
char s[N];
int main()
{
	int i,j,k,l,m;
	scanf("%s",s+1);
	for(i=1;i<=10;i++) if(s[i]=='1') w.pb(i);
	scanf("%i",&m);
	dp[0][0][0]=1;
	for(i=1;i<=m;i++)
	{
		int f=i&1?1:-1;
		for(j=0;j<N;j++)
		{
			for(l=-10;l<=10;l++)
			{
				for(k=0;k<w.size();k++)
				{
					if(j!=w[k] && dp[i-1][j][l])
					{
						dp[i][w[k]][l+f*w[k]]=1;
						go[i][w[k]][l+f*w[k]]=j;
					}
				}
			}
		}
		if(i&1) for(j=-20;j<=0;j++) for(k=0;k<N;k++) dp[i][k][j]=0;
		else for(j=0;j<20;j++) for(k=0;k<N;k++) dp[i][k][j]=0;
	}
	int g=-15,p=-15;
	for(i=-10;i<=10;i++)
	{
		for(j=0;j<N;j++)
		{
			if(dp[m][j][i])
			{
				p=j;
				g=i;
			}
		}
	}
	if(g==-15) printf("NO\n");
	else
	{
		printf("YES\n");
		vector<int> sol;
		i=m;
		while(i)
		{
			sol.pb(p);
			p=go[i][p][g];
			if(i&1) g-=sol.back();
			else g+=sol.back();
			i--;
		}
		reverse(sol.begin(),sol.end());
		for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	}
	return 0;
}