#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

#define ll long long

int t, n, A[N];
long long S;
int Tag = 1;

map < ll, int> Map;

void rmain() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
	scanf("%d", &A[i]);
	Map.clear();
	Tag = 1; S = 0;
	
	long long ans = 0;
	
	for(int i = n; i >= 1; -- i) {
		if(!A[i]) ++ ans;
		ans += Map[(A[i] - S) * (Tag)];
		S = A[i] - S;
		Tag = -Tag;
		++ Map[(A[i] - S) * (Tag)];
		while(Map.size()) {
			map < ll, int> :: iterator it = Map.begin();
			if(Tag == -1) {
				it = Map.end();
				-- it;
			}
			if(Tag * (it -> first) + S < 0) {
				Map.erase(it);
			}
			else break;
		}
	}
	cout << ans << endl;
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}