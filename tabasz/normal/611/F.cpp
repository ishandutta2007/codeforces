#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
const LL mod=1e9+7;

int l, n[2], ind[4], pos[4], M[][2]={{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int T[500005];
char C[500005];
PII B[2][500005];
LL res, R[2][500005];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d%s", &l, n+1, n, C);
	ind[0]=1;
	ind[1]=1;
	ind[2]=n[0];
	ind[3]=n[1];
	for(int i=0; i<l; i++)
	{
		if(C[i]=='R')
			T[i+1]=0;
		if(C[i]=='U')
			T[i+1]=1;
		if(C[i]=='L')
			T[i+1]=2;
		if(C[i]=='D')
			T[i+1]=3;
	}
	for(int i=1; i<=l; i++)
	{
		for(int j=0; j<2; j++)
			pos[j]+=M[T[i]][j];
		for(int j=0; j<2; j++)
		{
			if(ind[j]+pos[j%2]<1)
			{
				B[j][ind[j]]=MP(ind[1-j], ind[3-j]);
				R[j][ind[j]]=i;
				//printf("%d %d: %d %d\n", j, ind[j], B[j][ind[j]].F, B[j][ind[j]].S);
				res+=(LL)i*(ind[3-j]-ind[1-j]+1);
				res%=mod;
				ind[j]++;
			}
		}
		for(int j=2; j<4; j++)
		{
			if(pos[j%2]+ind[j]>n[j%2])
			{
				B[j%2][ind[j]]=MP(min(ind[j-1], ind[(j+1)%4]), max(ind[j-1], ind[(j+1)%4]));
				R[j%2][ind[j]]=i;
				//printf("%d %d: %d %d\n", j%2, ind[j], B[j%2][ind[j]].F, B[j%2][ind[j]].S);
				res+=(LL)i*(abs(ind[(j+1)%4]-ind[j-1])+1);
				res%=mod;
				ind[j]--;
			}
		}
		if(ind[0]>ind[2] || ind[1]>ind[3])
		{
			printf("%d\n", (int)res);
			return 0;
		}
	}
	if(pos[0]==0 && pos[1]==0)
	{
		printf("-1\n");
		return 0;
	}
	//printf("%d %d %d %d %d %d %d\n", pos[0], pos[1], ind[0], ind[1], ind[2], ind[3], res);
	while(ind[0]<=ind[2] && ind[1]<=ind[3])
	{
		for(int i=0; i<4; i++)
		{
			if(ind[i%2]>ind[i%2+2])
				continue;
			int x=ind[i]+pos[i%2], a=ind[1-i%2]+pos[1-i%2], b=ind[3-i%2]+pos[1-i%2];
			if(R[i%2][x]!=0 && B[i%2][x].F<=a && B[i%2][x].S>=b)
			{
				//printf("%d %d %d %d %d\n", i%2, x, a, b, R[i%2][x]+l);
				R[i%2][ind[i]]=R[i%2][x]+l;
				res+=R[i%2][ind[i]]*(b-a+1);
				res%=mod;
				B[i%2][ind[i]]=MP(ind[1-i%2], ind[3-i%2]);
				if(i<2)
					ind[i]++;
				else
					ind[i]--;
			}
		}
	}
	printf("%d\n", (int)res);
	return 0;
}