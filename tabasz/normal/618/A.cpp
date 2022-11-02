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

vector<int> V;
int n;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		V.PB(1);
		while((int)V.size()>1 && V[V.size()-1]==V[V.size()-2])
		{
			V[V.size()-2]++;
			V.pb();
		}
	}
	for(int i=0; i<(int)V.size(); i++)
		printf("%d ", V[i]);
	printf("\n");
	return 0;
}