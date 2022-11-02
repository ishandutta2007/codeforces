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

int n;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n >> s;
	if((int)s[3]>(int)'5')
		s[3]='5';
	if(n==12)
	{
		if((int)s[1]>(int)'2')
			s[0]='0';
		else
		{
			if(s[1]=='0')
				s[0]='1';
			else if((int)s[0]>(int)'1')
				s[0]='1';
		}
	}
	if(n==24)
	{
		if((int)s[0]>(int)'2')
			s[0]='0';
		else
		{
			if(s[0]=='2' && (int)s[1]>=(int)'4')
				s[1]='0';
		}
	}
	cout<< s << '\n';
	return 0;
}