#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

std::map <std::string, std::multiset <int>> Hash;
int n, k;
char s[N];

std::string pal(std::string s){
	std::string ret = "";
	for (int i = 0; i < n; ++ i){
		ret += s[n - 1 - i];
	}
	return ret;
}

int main(){
	scanf("%d%d", &k, &n);
	for (int i = 0, x; i < k; ++ i){
		scanf("%s%d", s, &x);
		Hash[s].insert(-x);
	}
	ll ans = 0;
	int max = -INT_MAX, min = INT_MAX;
	for (auto u = Hash.begin(); u != Hash.end(); ++ u){
		std::string str = pal(u -> first);
		if (str == u -> first){
			auto &v = u -> second;
			while (v.size()){
				auto w = v.begin();
				if (v.size() == 1){
					if (-*w >= 0){
						max = std::max(max, -*w);
					}
					break;
				}
				else{
					int x = -*w;
					++ w;
					int y = -*w;
					if (x >= 0 && y >= 0){
						ans += x + y;
						for (int i = 0; i < 2; ++ i){
							v.erase(v.begin());
						}
						continue;
					}
					else if (x >= 0 && y < 0){
						if (x + y >= 0){
							ans += x + y;
							min = std::min(min, y);
						}
						else{
							max = std::max(max, x);
						}
					}
					break;
				}
			}
		}
		else{
			if (Hash.count(str)){
				auto &v = u -> second, &v2 = Hash[str];
				int x = 0;
				while (x >= 0 && v.size() >= 1 && v2.size() >= 1){
					auto w = v.begin(), w2 = v2.begin();
					x = -*w - *w2;
					if (x >= 0){
						ans += x;
						v.erase(v.begin());
						v2.erase(v2.begin());
					}
					else{
						break;	
					}
				}
			}
		}
	}
	int x = std::max(max, -min);
	if (x != -INT_MAX){
		ans += x;
	}
	return printf("%I64d\n", ans), 0;	
}