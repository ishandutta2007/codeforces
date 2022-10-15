/*input
4
LDUR
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	string S;
	cin >> S;
	map<char, int>C;
	for (char x : S)
		C[x]++;
	cout << (min(C['U'], C['D']) + min(C['L'], C['R'])) * 2 << "\n";


}