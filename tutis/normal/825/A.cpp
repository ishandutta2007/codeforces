/***
9
110011101
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int>A;
	int curr = 0;
	for (char i : s)
	{
		if (i == '0')
		{
			A.push_back(curr);
			curr = 0;
		}
		else
			curr++;
	}
	A.push_back(curr);
	for (int i : A)
		cout << i;
}