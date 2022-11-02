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
string a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n >> a >> b;
	if(b[0]=='m')
	{
		if(n<30)
			cout<< "12\n";
		if(n==30)
			cout<< "11\n";
		if(n==31)
			cout<< "7\n";
		return 0;
	}
	if(n==5 || n==6)
		cout<< "53\n";
	else
		cout<< "52\n";
	return 0;
}