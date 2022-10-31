#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <map>
#include <set>

using namespace std;
typedef long long lli;

int n,k;
char str[101];
int cnt[26];

int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",str);
	for(int i=0;i<n;i++) cnt[str[i]-'a']++;
	for(int i=0;i<26;i++) {
		if(cnt[i]>k) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}