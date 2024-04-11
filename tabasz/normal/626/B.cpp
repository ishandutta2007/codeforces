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

int n, r, g, b;
string s;

int main()
{
	//ios_base::sync_with_stdio(0);
	cin>> n >> s;
	for(int i=0; i<n; i++)
	{
		if(s[i]=='B')
			b++;
		if(s[i]=='G')
			g++;
		if(s[i]=='R')
			r++;
	}
	if(min(r, min(g, b)))
	{
		printf("BGR\n");
		return 0;
	}
	if(b==0 && g==0)
	{
		printf("R\n");
		return 0;
	}
	if(b==0 && r==0)
	{
		printf("G\n");
		return 0;
	}
	if(r==0 && g==0)
	{
		printf("B\n");
		return 0;
	}
	if(r==0)
	{
		if(min(b, g)>1)
		{
			printf("BGR\n");
			return 0;
		}
		if(b>1)
		{
			printf("GR\n");
			return 0;
		}
		if(g>1)
		{
			printf("BR\n");
			return 0;
		}
		printf("R\n");
		return 0;
	}
	if(g==0)
	{
		if(min(b, r)>1)
		{
			printf("BGR\n");
			return 0;
		}
		if(b>1)
		{
			printf("GR\n");
			return 0;
		}
		if(r>1)
		{
			printf("BG\n");
			return 0;
		}
		printf("G\n");
		return 0;
	}
	if(b==0)
	{
		if(min(r, g)>1)
		{
			printf("BGR\n");
			return 0;
		}
		if(r>1)
		{
			printf("BG\n");
			return 0;
		}
		if(g>1)
		{
			printf("BR\n");
			return 0;
		}
		printf("B\n");
		return 0;
	}
	return 0;
}