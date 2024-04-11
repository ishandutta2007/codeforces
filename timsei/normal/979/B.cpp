#include <bits/stdc++.h>
using namespace std;

const int N = 111111;

#define tint long long

const string name[3] = {"Kuro", "Shiro" , "Katie"};

char s[N];
int n , ans[4];

map <int , int> Map;

int solve(char *s) {
	int len = strlen(s + 1);
	if(n > len)
	return len;
	Map.clear();
	int cxt = 0;
	for(int i = 1;i <= len;++ i) {
		cxt = max(cxt , ++ Map[s[i]]);
	}
	if(n == 1 && cxt == len) {
		return len - 1;
	}
	return min(len , cxt + n);
}

main(void) {
	cin >> n;
	int res = -1;
	for(int i = 0;i < 3;++ i) {
		scanf("%s" , s + 1);
		ans[i] = solve(s);
		res = max(res , ans[i]);
	}
	int tot = 0;
	for(int i = 0;i < 3;++ i) {
		if(ans[i] == res)
		++ tot;
	}
	if(tot > 1) {
		puts("Draw");
		return 0;
	}
	for(int i = 0;i < 3;++ i) {
		if(ans[i] == res) {
			cout << name[i] << endl;
		}
	}
}