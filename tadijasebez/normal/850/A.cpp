#include <stdio.h>
#include <vector>
using namespace std;
const int N=1050;
int P[N][5];
int Calc(int i, int j)
{
	int k,ans=0;
	for(k=0;k<5;k++) ans+=P[i][k]*P[j][k];
	return ans;
}
vector<int> sol;
int main()
{
	int n,i,j,k;
	scanf("%i",&n);
	for(i=0;i<n;i++) for(j=0;j<5;j++) scanf("%i",&P[i][j]);
	bool ok;
	for(i=0;i<n;i++)
	{
		ok=false;
		for(j=0;j<n;j++) if(j!=i && !ok)
		{
			for(k=0;k<n;k++) if(k!=i && k!=j)
			{
				if(Calc(i,i)-Calc(i,j)-Calc(i,k)+Calc(j,k)>0)
				{
					ok=true;
					break;
				}
			}
		}
		if(!ok) sol.push_back(i+1);
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	return 0;
}