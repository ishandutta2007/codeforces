/*input
Danil_and_Olya
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string S;
	cin >> S;
	set<string>X = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	int kiek = 0;
	for (int i = 0; i < S.size(); i++)
	{
		string s;
		for (int j = i; j < S.size(); j++)
		{
			s.push_back(S[j]);
			kiek += X.count(s);
		}
	}
	if (kiek == 1)
		cout << "YES\n";
	else
		cout << "NO\n";
}