#include<bits/stdc++.h>
#define ll long long

int a, b, c, n;
std::multiset <std::pair <int, bool>> orz;

int main(){
	scanf("%d%d%d%d", &a, &b, &c, &n);
	for (int i = 0, x; i < n; ++ i){
		char s[10];
		scanf("%d%s", &x, s);
		orz.insert({x, s[0] == 'U'});
	}
	ll cnt = 0, ans = 0;
	while (orz.size()){
		auto u = *(orz.begin());
		orz.erase(orz.begin());
		if (u.second){
			if (a){
				-- a;
			}
			else if (c){
				-- c;
			}
			else{
				continue;
			}
			++ cnt;
			ans += u.first;
		}
		else{
			if (b){
				-- b;
			}
			else if (c){
				-- c;
			}
			else{
				continue;
			}
			++ cnt;
			ans += u.first;
		}
	}
	return printf("%I64d %I64d\n", cnt, ans), 0;
}