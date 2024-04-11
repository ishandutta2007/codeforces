#include <cstdio>
#include <iostream>
#include <string>
 
using namespace std;
const int Nmax = 1e6 + 5;
 
string s;
int N, cnt;
bool Add[Nmax];
 
int main()
{
	ios :: sync_with_stdio(false);
	
	cin >> s; N = s.size();
	for (int i = 0; i < N; ++ i) {
		if (!i || s[i] ^ s[i - 1]) Add[++ cnt] = 1;
		else Add[cnt] = 0;
	}
	if (s[0] == s[N - 1]) Add[1] = 0, -- cnt;
	
	int temp = 0, ans = 0;
	for (int i = 1; i <= cnt; ++ i) {
		if (Add[i]) ++ temp;
		else ans += (temp >> 1) + 1, temp = 0;
	}
	cout << ans + (temp >> 1) << endl;
	
	return 0;
}