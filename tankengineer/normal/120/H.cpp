#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;


const int N = 200;
vector<int> edge[N];
int n, stamp, vis[N], match[27 * 27 * 27 * 27], matchi[N];
char word[N][11];

void proc(int i) {
	int l = strlen(word[i]);
	char *s = word[i];
	for (int a = 0; a < l; ++a) {
		for (int b = a + 1; b < l + 1; ++b) {
			for (int c = min(b + 1, l); c < l + 1; ++c) {
				for (int d = min(c + 1, l); d < l + 1; ++d) {
					int h = 0;
					h = s[a] - 'a' + 1;
					if (b != l) {
						h += (s[b] - 'a' + 1) * 27;
					}
					if (c != l) {
						h += (s[c] - 'a' + 1) * 27 * 27;
					}
					if (d != l) {
						h += (s[d] - 'a' + 1) * 27 * 27 * 27;
					}
					edge[i].push_back(h);
				}
			}
		}
	}
}

int find(int i) {
	if (vis[i] == stamp) {
		return 0;
	}
	vis[i] = stamp;
	for (int j = 0; j < (int)edge[i].size(); ++j) {
		int v = edge[i][j];
		if (match[v] == -1 || find(match[v])) {
			match[v] = i;
			matchi[i] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", word[i]);
		proc(i);
	}
	memset(vis, -1, sizeof(vis));
	memset(match, -1, sizeof(match));
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		stamp = i;
		ans += find(i);
	}
	if (ans == n) {
		for (int i = 0; i < n; ++i) {
			int tmp = matchi[i];
			while (tmp) {
				printf("%c", tmp % 27 + 'a' - 1);
				tmp /= 27;
			}
			printf("\n");
		}
	} else {
		printf("-1\n");
	}
	return 0;
}