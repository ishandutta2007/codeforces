/*input
5
2 4 5 1 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int A[n + 1];
	int KUR[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	for (int i = 1; i <= n; i++)
	{
		KUR[A[i]] = i;
	}
	int kiek = 0;
	for (int i = 1; i <= n; i++)
	{
		if (A[i] == i)
			continue;
		kiek++;
		int k = KUR[i];
		swap(A[i], A[k]);
		KUR[A[i]] = i;
		KUR[A[k]] = k;
	}
	if (kiek % 2 == (3 * n) % 2)
		cout << "Petr\n";
	else
		cout << "Um_nik\n";

}