#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 2e5 + 5;
#define PI 3.14159265358979
int am[6],t[100000],o[100000];
int hi(string s) {
	if (s == "S")return 0;
	if (s == "M")return 1;
	if (s == "L")return 2;
	if (s == "XL")return 3;
	if (s == "XXL")return 4;
	if (s == "XXXL")return 5;
}
string to[6] = { "S","M","L","XL","XXL","XXXL" };
string ans[100000];
int main() {
	int n,i,j;
	for (i = 0; i < 6; i++)scanf("%d", am + i);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		string s;
		cin >> s;
		int pos=999;
		if(s.find_first_of(',')!=string::npos)pos= s.find_first_of(',');
		if (pos != 999)s = s.substr(0, pos);
		if (pos != 999)o[i]=1;
		t[i]=hi(s);
	}
	for (i = 0; i < 6; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0)break;
			if (o[j] == 0)continue;
			if (t[j] != i-1)continue;
			if (ans[j] != "")continue;
			if (am[i] == 0) {
				printf("NO"); return 0;
			}
			am[i]--;
			ans[j] = to[i];
		}
		for (j = 0; j < n; j++) {
			if (o[j])continue;
			if (t[j] != i)continue;
			if (am[i] == 0) {
				printf("NO"); return 0;
			}
			am[i]--;
			ans[j] = to[i];
		}
		for (j = 0; j < n; j++) {
			if (o[j] == 0)continue;
			if (t[j] != i)continue;
			if (am[i] == 0)continue;
			if (ans[j] != "")continue;
			am[i]--;
			ans[j] = to[i];
		}
	}

	printf("YES\n");
	for (i = 0; i < n; i++)cout << ans[i] << "\n";
}