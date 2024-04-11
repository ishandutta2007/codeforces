/***
992
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int>A = {1, 6, 28, 120, 496, 2016, 8128, 32640};
	sort(A.begin(), A.end(), [](int a, int b) {return b < a;});
	for (int i : A)
		if (n % i == 0)
		{
			cout << i;
			return 0;
		}

}