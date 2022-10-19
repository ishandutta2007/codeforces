#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n , m , a[N], s[N] , top , ans = 0;

int main(void) {
    for(int i = scanf("%d" , &n);i <= n;++ i) scanf("%d" , &a[i]);
    for(int i = 1;i <= n;++ i) {
	while(1) {
	    if(!top) break;
	    if(s[top] < a[i]) -- top; else break;
	}
	if(top) {
	    ans = max(ans , s[top] ^ a[i]);
	}
	s[++ top] = a[i];
    }
    top = 0;
    for(int i = n;i >= 1;-- i) {
	while(1) {
	    if(!top) break;
	    if(s[top] < a[i]) -- top; else break;
	}
	if(top) {
	    ans = max(ans , s[top] ^ a[i]);
	}
	s[++ top] = a[i];
    }
    cout << ans;
}