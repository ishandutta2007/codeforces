#include<bits/stdc++.h>
#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MM = 1e9 + 7;
const int MAXN = 2e6 + 10;

int a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	map<int, int> mp, mp2;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		mp[a[i]] = 1;
	}
	int cnt = 0;
	for (auto &x : mp){
		cnt++;
		x.second = cnt;
		mp2[cnt] = x.first;
	}
	for (int i = 1; i <= n; i++){
		printf("%d%c", mp2[(mp[a[i]] % n) + 1], " \n"[i == n]);
	}
	return 0;
}