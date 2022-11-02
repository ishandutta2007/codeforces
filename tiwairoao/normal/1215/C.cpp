#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 200000;
vector<int>v1, v2;
int cnt[2], n;
char s[2][MAXN + 5];
int main() {
	scanf("%d%s%s", &n, s[0] + 1, s[1] + 1);
	for(int i=1;i<=n;i++)
		cnt[s[0][i] - 'a']++, cnt[s[1][i] - 'a']++;
	if( (cnt[0] & 1) || (cnt[1] & 1) ) {
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++) {
		if( s[0][i] == 'a' && s[1][i] == 'b' ) v1.push_back(i);
		if( s[0][i] == 'b' && s[1][i] == 'a' ) v2.push_back(i);
	}
	if( v1.size() & 1 ) {
		printf("%d\n", v1.size()/2 + v2.size()/2 + 2);
		for(int i=1;i<v1.size();i+=2)
			printf("%d %d\n", v1[i], v1[i + 1]);
		for(int i=1;i<v2.size();i+=2)
			printf("%d %d\n", v2[i], v2[i + 1]);
		printf("%d %d\n", v1[0], v1[0]);
		printf("%d %d\n", v1[0], v2[0]);
	}
	else {
		printf("%d\n", v1.size()/2 + v2.size()/2);
		for(int i=0;i<v1.size();i+=2)
			printf("%d %d\n", v1[i], v1[i + 1]);
		for(int i=0;i<v2.size();i+=2)
			printf("%d %d\n", v2[i], v2[i + 1]);
	}
}