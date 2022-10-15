/*input
5 1
BGGBG
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int N, T;
	cin >> N >> T;
	string S;
	cin >> S;
	while (T--)
	{
		for (int i = 0; i + 1 < S.size(); i++)
		{
			if (S[i] == 'B' && S[i + 1] == 'G')
			{
				swap(S[i], S[i + 1]);
				i++;
			}
		}
	}
	cout << S << "\n";
}