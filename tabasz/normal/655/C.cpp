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

int n, k, res=1000000;
vector<int> V;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n >> k >> s;
	for(int i=0; i<n; i++)
		if(s[i]=='0')
			V.PB(i);
	for(int i=0; i+k<(int)V.size(); i++)
	{
		int st=i, en=i+k, mid=(st+en)/2;
		while(st<=en)
		{
			res=min(res, max(V[mid]-V[i], V[i+k]-V[mid]));
			if(V[mid]-V[i]>=V[i+k]-V[mid])
				en=mid-1;
			else
				st=mid+1;
			mid=(st+en)/2;
		}
	}
	printf("%d\n", res);
	return 0;
}