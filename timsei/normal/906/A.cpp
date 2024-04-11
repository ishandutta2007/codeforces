#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
using namespace std;

const int N = 1e6 + 5;

char s[N] , ty[N];
int n , m , len , num[105] , vis[30];

bool can = 0;

int ans = 0;

int main(void) {
	scanf("%d\n" , &n);
	for(int i = 0;i < 26;++ i) num[i] = 1;
	for(int i = 1;i <= n;++ i) {
		scanf("%s%s" , ty , s + 1);
		if(ty[0] == '!') {
			if(can) {
				++ ans; continue;
			}
			len = strlen(s + 1);
			memset(vis , 0 , sizeof(vis));
			for(int j = 1;j <= len;++ j) {
				vis[s[j] - 'a'] = 1;
			}
			for(int j = 0;j < 26; ++ j) if(!vis[j]) num[j] = 0;
		}
		if(ty[0] == '?') {
			if(can) {
				++ ans; continue;
			}
			num[s[1] - 'a'] = 0;
		}
		if(ty[0] == '.') {
			len = strlen(s + 1);
			memset(vis , 0 , sizeof(vis));
			for(int j = 1;j <= len;++ j) {
				vis[s[j] - 'a'] = 1;
			}
			for(int j = 0;j < 26; ++ j) if(vis[j]) num[j] = 0;			
		}
		int tot = 0;
		for(int j = 0;j < 26;++ j) tot += num[j];
		if(tot == 1) can = 1;
	}
	cout << ans - can << endl;
}