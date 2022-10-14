#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<long long>
int main() {
	ll tt;
	cin >> tt;
	while(tt--) {
		ll s;
		cin >> s;
		vll ar(s);
		int cnt[101];
		memset(cnt, 0, sizeof(cnt));
		for(int i =0; i < s; i++) {
			cin >> ar[i];
			++cnt[ar[i]];
		}
		pair<ll, ll> answer;
		bool fs=true;
		for(int i =0; i < 101; i++) {
			if(fs&&!cnt[i]) {
				fs=false;
				answer.first = i;
				break;
			}
		}
		for(int i =0; i < 101; i++) {
			if(cnt[i]<=1) {
				answer.second = i;
				break;
			}
		}

	printf("%lld\n", answer.first+answer.second);		
	}
}