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

string s[50004];
int n;

bool cmp(string a, string b)
{
	return a+b<b+a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n;
	for(int i=0; i<n; i++)
		cin>> s[i];
	sort(s, s+n, cmp);
	for(int i=0; i<n; i++)
		cout<< s[i];
	cout<< '\n';
	return 0;
}