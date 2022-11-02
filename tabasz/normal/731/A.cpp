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
char c='a';
int res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> s;
	for(int i=0; i<s.size(); i++)
	{
		res+=min(abs((int)s[i]-(int)c), 26-abs((int)s[i]-(int)c));
		//cout<< res << '\n';
		c=s[i];
	}
	cout<< res << '\n';
	return 0;
}