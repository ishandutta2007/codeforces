#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000;

int l[N + 5]; char s[N + 5];
bool same(int x) {
	for(int i=l[x-1]+1;i<l[x];i++)
		if( s[i] != s[i - 1] ) return false;
	return true;
}
int get(int x, char c) {
	if( !x ) return 0;
	if( !same(x) || s[l[x-1]] != c ) {
		int ret = 0, lst = (s[l[x-1]] == c ? l[x-1] : l[x-1] + 1);
		for(int i=l[x-1];i<l[x];i++)
			if( s[i] != c ) ret = max(ret, i - lst), lst = i + 1;
		ret = max(ret, l[x] - lst);
		
		int tmp = 0;
		for(int i=l[x]-1;s[i]==c;i--) tmp++;
		for(int i=l[x-1];s[i]==c;i++) tmp++;
		for(int i=0;i<l[x-1];i++)
			if( s[i] == c ) {
				ret = max(ret, tmp + 1);
				break;
			}
		
		return ret;
	} else {
		int p = get(x - 1, c);
		
		return p + (p + 1) * (l[x] - l[x - 1]);
	}
}
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%s", s + l[i - 1]), l[i] = l[i - 1] + strlen(s + l[i - 1]);
	
	if( !same(n) ) {
		int ans = 0, lst = l[n - 1];
		for(int i=l[n-1];i<l[n];i++)
			if( s[i] != s[lst] ) ans = max(ans, i - lst), lst = i;
		ans = max(ans, l[n] - lst);
		
		if( s[l[n-1]] == s[l[n]-1] ) {
			int tmp = 0;
			for(int i=l[n]-1;s[i]==s[l[n]-1];i--) tmp++;
			for(int i=l[n-1];s[i]==s[l[n-1]];i++) tmp++;
			for(int i=0;i<l[n-1];i++)
				if( s[i] == s[l[n-1]] ) {
					ans = max(ans, tmp + 1);
					break;
				}
		} else {
			int tmp = 0;
			for(int i=l[n]-1;s[i]==s[l[n]-1];i--) tmp++;
			for(int i=0;i<l[n-1];i++)
				if( s[i] == s[l[n]-1] ) {
					ans = max(ans, tmp + 1);
					break;
				}
			
			tmp = 0;
			for(int i=l[n-1];s[i]==s[l[n-1]];i++) tmp++;
			for(int i=0;i<l[n-1];i++)
				if( s[i] == s[l[n-1]] ) {
					ans = max(ans, tmp + 1);
					break;
				}
		}
		printf("%d\n", ans);
	} else {
		int p = get(n - 1, s[l[n]-1]);
		printf("%d\n", p + (p + 1) * (l[n] - l[n - 1]));
	}
}