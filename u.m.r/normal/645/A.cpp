#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const double eps = 1e-9;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

char s[MAXN];
vector<int> a,b;

int main(){
	a.clear(),b.clear();
	scanf("%s", s);
	if (s[0] != 'X') a.push_back(s[0]-'A');
	if (s[1] != 'X') a.push_back(s[1]-'A');
	scanf("%s", s);
	if (s[1] != 'X') a.push_back(s[1]-'A');
	if (s[0] != 'X') a.push_back(s[0]-'A');
	scanf("%s", s);
	if (s[0] != 'X') b.push_back(s[0]-'A');
	if (s[1] != 'X') b.push_back(s[1]-'A');
	scanf("%s", s);
	if (s[1] != 'X') b.push_back(s[1]-'A');
	if (s[0] != 'X') b.push_back(s[0]-'A');
	int flag = 0;
	for(int i = 0; i < 3; i++){
		int ff = 1;
		for(int j = 0; j < 3; j++)
			if (a[j] != b[(i + j) % 3])
				ff = 0;
		flag |= ff;
	}
	if (flag)
		puts("YES");
	else
		puts("NO");
	return 0;
}