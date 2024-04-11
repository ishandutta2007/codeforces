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

string s[7]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"}, a, b;

int main()
{
	cin>> a >> b;
	int x, y;
	for(int i=0; i<7; i++)
	{
		if(a==s[i])
			x=i;
		if(b==s[i])
			y=i;
	}
	if((x+31)%7==y || (x+30)%7==y || (x+28)%7==y)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}