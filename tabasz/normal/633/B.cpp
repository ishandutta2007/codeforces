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

int m;
vector<int> V;

int main()
{
	//ios_base::sync_with_stdio(0);
	int a=0, ind=1;
	scanf("%d", &m);
	while(a<=m)
	{
		int x=ind;
		while(x%5==0)
		{
			a++;
			x/=5;
		}
		if(a==m)
			V.PB(ind);
		ind++;
	}
	printf("%d\n", (int)V.size());
	for(int i=0; i<(int)V.size(); i++)
		printf("%d ", V[i]);
	printf("\n");
	return 0;
}