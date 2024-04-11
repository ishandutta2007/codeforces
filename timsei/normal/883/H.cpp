#include <bits/stdc++.h>
using namespace std;

const int N = 800005;

int num[N] , n;
char s[N] , out[N];
vector<char>now;

int main(void) {
	scanf("%d" , &n);
	scanf("%s" , s + 1);
	for(int i = 1;i <= n;i ++) {
		num[s[i]] ++;
	}
	int odd = 0;
	for(int i = 0;i < 256;i ++) if(num[i] % 2 == 1) odd ++;
	int tot = 0;
	if(!odd) {
		puts("1");
		for(int i = 0;i < 256;i ++) if(num[i]) {
			while(num[i]) {
				out[++ tot] = i; out[n - tot + 1] = i;
				num[i] -= 2; 
			}
		}
		puts(out + 1);
		return 0;
	}
	int mx = 0;
	for(int i = 1;i <= n;i += 2) {
		if(n % i == 0) {
			if(n / i >= odd) {
				mx = i;
			}
		}
	}
	printf("%d\n" , n / mx);
	for(int i = 0;i < 256;i ++) {
		if(num[i] % 2) now.push_back(i) , num[i] --;
	}
		
	int it = 0 , pa = 0;
	while(now.size() < n / mx) {
		while(!num[pa] && pa < 256) pa ++;
		if(pa == 256) break;
		if(now.size() == n / mx) break;
		now.push_back(pa); now.push_back(pa);
		num[pa] -= 2;
	}
	if(mx == 1) {
		for(int i = 1;i <= n;i ++) {
			putchar(s[i]); putchar(' ');
		}
		return 0;
	}
	for(int i = 1;i <= n / mx;i ++) {
		out[mx / 2 + 1] = now[it ++];
		while(!num[pa] && pa < 256) pa ++;
		if(pa == 256) continue;
		int tot = 0;
		while(1) {
			while(!num[pa] && pa < 256) pa ++;
			if(pa == 256) break;
			out[++ tot] = pa; out[mx - tot + 1] = pa;num[pa] -= 2;
			if(tot == mx / 2) break;
		}
		for(int j = 1;j <= mx;j ++) putchar(out[j]);  putchar(' ');
	}
}