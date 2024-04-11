#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 7;

int n;
int in[N];
int pref[N];

void solve(){
	scanf("%d", &n);
	for(int i = 0; i <= n + n; ++i)
		in[i] = pref[i] = 0;
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		in[a]++;
	}
	
	for(int i = 1; i <= n; ++i)
		pref[in[i]]++;
	
	for(int i = 1; i <= n + n; ++i)
		pref[i] += pref[i - 1];
	
	int ans = 2;
	for(int i = 3; i <= n; ++i){
		int cur = pref[0];
		for(int j = 1; (j - 1) * i <= n; ++j)
			cur += pref[j * i] - pref[max(j * i - j - 1, (j - 1) * i)];
		
		if(cur == n)
			ans = i;
	}
	
	int res = 0;
	for(int i = 1; (i - 1) * ans <= n; ++i)
		res += i * (pref[i * ans] - pref[max(i * ans - i - 1, (i - 1) * ans)]);
	printf("%d\n", res);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}