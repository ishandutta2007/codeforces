/***
aba
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string A;
	cin >> A;
	string B = A;
	reverse(B.begin(), B.end());
	cout << A + B << endl;
}