#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string in[100001];
int c[26];
int ca[26];
vector<int> map[26];
int ind[26];
string res;

char tmp[2];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> in[i];
		for (int j = 0; j < 26; j++) c[j] = 0;
		for (int j = 0; j < in[i].length(); j++) {
			if (j != 0) map[in[i][j - 1] - 'a'].push_back(in[i][j] - 'a');
			c[in[i][j] - 'a']++;
			ca[in[i][j] - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			if (c[j] > 1) {
				printf("NO\n");
				return 0;
			}
			c[j] = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		sort(map[i].begin(), map[i].end());
		map[i].erase(unique(map[i].begin(), map[i].end()), map[i].end());
		if (map[i].size() > 1) {
			printf("NO\n");
			return 0;
		}
		if (map[i].size() == 1) ind[map[i][0]]++;
	}
	for (int i = 0; i < 26; i++) {
		if (ca[i] > 0) cnt--;
		if (ind[i] > 1) {
			printf("NO\n");
			return 0;
		}
	}
	for(int i=0; i<26; i++){
		if (ind[i] == 0 && ca[i] > 0) {
			int t = i;
			tmp[0] = t + 'a';
			res.append(tmp);
			cnt++;
			while (map[t].size() > 0) {
				cnt++;
				t = map[t][0];
				tmp[0] = t + 'a';
				res.append(tmp);
			}
		}
	}
	if (cnt != 0) cout << "NO" << endl;
	else
		cout << res << endl;
	return 0;
}