#include<bits/stdc++.h>

const int N = 1000010;
const int moder = 1e9 + 7;

std::vector <std::set <int>> set;
std::vector <int> vec[N << 1], vec2[N << 1];
int n, m, sit[N << 1], cnt[N << 1], now_sit, fac[N << 1];
std::set <int> exi, exi2, exi3, s;

int main(){
	fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = 1ll * fac[i - 1] * i % moder;
	}
	memset(sit, -1, sizeof(sit));
	scanf("%d%d", &n, &m);
	for (int i = 0, siz; i < n; ++ i){
		for (auto u = exi.begin(); u != exi.end(); ++ u){
			cnt[*u] = 0;
		}
		exi.clear();
		scanf("%d", &siz);
		for (int j = 0, x; j < siz; ++ j){
			scanf("%d", &x);
			++ cnt[x];
			exi.insert(x);
		}
		for (auto u = exi2.begin(); u != exi2.end(); ++ u){
			vec[*u].clear();
		}
		exi2.clear();
		for (auto u = exi.begin(); u != exi.end(); ++ u){
			vec[cnt[*u]].push_back(*u);
			exi2.insert(cnt[*u]);
		}
		if (!i){
			int __cnt = 0;
			for (auto u = exi2.begin(); u != exi2.end(); ++ u, ++ __cnt){
				s.clear();
				for (int k = 0; k < vec[*u].size(); ++ k){
					if (sit[vec[*u][k]] != -1){
						break;
					}
					s.insert(vec[*u][k]);
					sit[vec[*u][k]] = __cnt;
				}
				set.push_back(s);
			}
			s.clear();
			for (int j = 1; j <= m; ++ j){
				if (sit[j] == -1){
					sit[j] = exi2.size();
					s.insert(j);
				}
			}
			set.push_back(s);
			now_sit = exi2.size() + 1;
		}
		else{
			for (auto u = exi2.begin(); u != exi2.end(); ++ u){
				for (auto v = exi3.begin(); v != exi3.end(); ++ v){
					vec2[*v].clear();
				}
				exi3.clear();
				for (int k = 0; k < vec[*u].size(); ++ k){
					int x = vec[*u][k];
					vec2[sit[x]].push_back(x);
					exi3.insert(sit[x]);
				}
				for (auto v = exi3.begin(); v != exi3.end(); ++ v){
					s.clear();
					for (int j = 0; j < vec2[*v].size(); ++ j){
						int x = vec2[*v][j];
						set[sit[x]].erase(x);
						sit[x] = now_sit;
						s.insert(x);
					}
					++ now_sit;
					set.push_back(s);
				}
			}
		}
		/*for (int i = 0; i < set.size(); ++ i){
			printf("%d ", set[i].size());
			putchar('\n');
		}*/
	}
	int ans = 1;
	for (int i = 0; i < set.size(); ++ i){
		ans = 1ll * ans * fac[set[i].size()] % moder;
	}
	printf("%d\n", ans);
	return 0;
}