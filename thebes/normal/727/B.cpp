#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 2e5 + 5;
#define PI 3.14159265358979
double ans;
vector<string> v;
double idk(string s) {
	double cur = 0;
	int n = s.size();
	double num = 0;
	if (s.size() > 3 && s[s.size() - 3]=='.')n -= 3,cur+=0.1*(s[s.size()-2]-'0')+0.01*(s[s.size()-1]-'0');
	for (int i = 0; i < n; i++) {
		if (i % 4 == (n) % 4)continue;
		num *= 10;
		num += s[i] - '0';
	}
	return num + cur;
}
int p[10];
int main() {
	string s;
	cin >> s;
	int i;
	v.push_back("");
	for (i = 0; i < s.size(); i++) {
		if (s[i] >= 'a'&&s[i] <= 'z'&&v[v.size() - 1].size())v.push_back("");
		if (s[i] >= 'a'&&s[i] <= 'z')continue;
		v[v.size() - 1].push_back(s[i]);
	}
	for (string k : v)ans += idk(k);
	int a = (int)ans;
	int aa = a;
	p[0] = 1;
	for (i = 1; i <= 9; i++)p[i] = p[i - 1] * 10;
	bool beg=0;
	for (i = 8; i >= 0; a%=p[i],i--) {
		if (i % 3 == 2 && aa >= p[i + 1])printf(".");
		if (a / p[i] == 0)if (beg)printf("0");
		if (a / p[i])beg = 1, printf("%d", a / p[i]);
	}
	if (aa==0)printf("0");
	ans -= aa;
	ans += 0.005;
	a = (ans * 100);
	if (a != 0)printf(".%02d", a);
}