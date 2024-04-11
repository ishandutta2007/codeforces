#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int cnt[26],n;
char str[100001];

int main() {
	scanf("%d%s",&n,str);
	if(n>26) {
		puts("-1");
		return 0;
	}
	
	for(int i=0;i<n;i++) cnt[str[i]-'a']++;
	int res=0;
	for(int i=0;i<26;i++) res+=max(0,cnt[i]-1);
	printf("%d\n",res);

	return 0;
}