#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, ans;
int cnt[25][25][25];

int ns[25];

vector<int> get;

void go(int now, int base) {
	if (now == 24) {
		ans ^= base * base;
		return;
	}
	go(now + 1, base);
	for (int i = now + 1; i < 24; ++i) {
		ns[i] -= cnt[now][i][24];
		for (int j = 0; j < (int)get.size(); ++j) {
			ns[i] += cnt[get[j]][now][i];	
		}
	}
	get.push_back(now);
	go(now + 1, base + ns[now]);
	get.pop_back();
	for (int i = now + 1; i < 24; ++i) {
		ns[i] += cnt[now][i][24];
		for (int j = 0; j < (int)get.size(); ++j) {
			ns[i] -= cnt[get[j]][now][i];	
		}
	}
}

int main() {
	scanf("%d", &n);	
	ans = 0;
	for (int _ = 0; _ < n; ++_) {
		char s[5];
		scanf("%s", s);
		vector<char> v;	
		for (int j = 0; j < 3; ++j) {
			v.push_back(s[j]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int i = 0; i < (int)v.size(); ++i) {
			++cnt[v[i] - 'a'][24][24];
			for (int j = i + 1; j < (int)v.size(); ++j) {
				++cnt[v[i] - 'a'][v[j] - 'a'][24];
				for (int k = j + 1; k < (int)v.size(); ++k) {
					++cnt[v[i] - 'a'][v[j] - 'a'][v[k] - 'a'];
				}
			}
		}
	}
	for (int i = 0; i < 24; ++i) {
		ns[i] = cnt[i][24][24];
	}
	go(0, 0);
	printf("%d\n", ans);	
	return 0;
}