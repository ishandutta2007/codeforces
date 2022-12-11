#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;   
const int mod = (int)1e9 + 7;

int add(int a, int b)
{
	return (a + b < mod ? a + b : a + b - mod);
}

int mult(int a, int b)
{                            
	ll c = (ll)a * (ll)b;
	return (int)(c % (ll)mod);
}

int binPow(int a, ll k)
{                                   
	if (k == 0)
		return 1;
	if (k & (ll)1)
		return mult(binPow(a, k - 1), a);
	else
	{
		int t = binPow(a, k / 2);
		return mult(t, t);
	}
}

int calcSum(int k, int a)
{                                                           
	if (k == 0)
		return 1;
	if (k & 1)
	{
		int t = calcSum(k / 2, a);     
		int ans = add(t, mult(t, binPow(2, (ll)(k / 2 + 1) * (ll)a)));
		return ans;
	}
	else
		return add(calcSum(k - 1, a), binPow(2, (ll)k * (ll)a));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
            
	string str;
	int k;
	cin >> str >> k;
	int t = calcSum(k - 1, (int)str.length());            
	int ans = 0;
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str[i] == '0' || str[i] == '5')
			ans = add(ans, t);
		t = mult(t, 2);
	}

	printf("%d", ans);

	return 0;
}