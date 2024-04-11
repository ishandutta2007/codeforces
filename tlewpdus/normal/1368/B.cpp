#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,pii> piii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
int cnt[10] = {0,};
char str[] = "codeforces";

int main(){
	ll k;

	scanf("%lld",&k);
	for (int i=0;i<10;i++) cnt[i] = 1;
	while(1) {
		ll mul = 1;
		for (int i=0;i<10;i++) mul *= cnt[i];
		if (mul>=k) break;
		int i = 8;
		for (;i>=0;i--) {
			if (cnt[i]>cnt[i+1]) break;
		}
		cnt[i+1]++;
	}
	for (int i=0;i<10;i++) {
		for (int j=0;j<cnt[i];j++) printf("%c",str[i]);
	}
	puts("");

	return 0;
}