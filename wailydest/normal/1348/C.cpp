#include <cstdio>
#include <string>
using namespace std;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		char buf[100001];
		scanf("%s", buf);
		int amt[26] = {0};
		for (int i = 0; i < n; ++i) ++amt[buf[i] - 'a'];
		bool isfirst = true;
		bool srt = false;
		string s;
		int last = -1;
		for (int i = 25; i >= 0 && last == -1; --i) {
			if (amt[i]) last = i;
		}
		int diff = 0;
		for (int i = 0; i < 26; ++i) diff += (bool)amt[i];
		if (diff > 2) last = -1;
		for (int i = 0; i < 26; ++i) if (amt[i]) {
			if (isfirst && amt[i] >= k) {
				amt[i] -= k;
				s.push_back('a' + i);
				srt = true;
			}
			if (isfirst && srt && amt[i]) {
				if (diff == 2) last = -1;
			}
			isfirst = false;
			if (srt && amt[i]) for (int j = 0; j < (i == last ? (amt[i] - 1) / k + 1 : amt[i]); ++j) s.push_back('a' + i);
			else k -= amt[i];
			if (k <= 0) {
				s.push_back('a' + i);
				break;
			}
		}
		printf("%s\n", s.c_str());
	}
	return 0;
}