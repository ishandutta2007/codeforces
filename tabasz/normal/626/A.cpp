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

string s;
int n, res, T[405][405];

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n >> s;
	int a=200, b=200;
	T[a][b]=1;
	for(int i=0; i<n; i++)
	{
		if(s[i]=='U')
			a++;
		if(s[i]=='D')
			a--;
		if(s[i]=='R')
			b++;
		if(s[i]=='L')
			b--;
		res+=T[a][b];
		T[a][b]++;
	}
	printf("%d\n", res);
	return 0;
}