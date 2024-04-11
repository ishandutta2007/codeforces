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

string s[4], a[4];


int main()
{
	ios_base::sync_with_stdio(0);
	for(int i=0; i<4; i++)
		cin>> s[i];
	for(int i=0; i<3; i+=2)
	{
		if(s[i][0]!='X')
			a[i]+=s[i][0];
		if(s[i][1]!='X')
			a[i]+=s[i][1];
		if(s[i+1][1]!='X')
			a[i]+=s[i+1][1];
		if(s[i+1][0]!='X')
			a[i]+=s[i+1][0];
	}
	a[0]+=a[0];
	a[2]+=a[2];
	int i1=0, i2=0;
	while(a[0][i1]!='A')
		i1++;
	while(a[2][i2]!='A')
		i2++;
	for(int i=0; i<3; i++)
	{
		if(a[0][i1+i]!=a[2][i2+i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}