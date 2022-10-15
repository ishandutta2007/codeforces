/*input
4
5 -6 -5 1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	set<int>A;
	while (n--)
	{
		int a;
		cin >> a;
		if (a != 0)
			A.insert(a);
	}
	cout << A.size() << "\n";


}