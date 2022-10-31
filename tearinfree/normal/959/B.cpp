#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>

using namespace std;

map<string, int> tr;
int cost[100000],n,m,k,pa[100000],cp[100000];

int find(int cur) {
	return cur==pa[cur] ? cur : pa[cur] = find(pa[cur]);
}
void merge(int a,int b) {
	int fa=find(a), fb=find(b);
	pa[fb] = fa;
	cp[fa] = min(cp[fa],cp[fb]);
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> m;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		tr[s] = i;
	}
	for(int i=0;i<n;i++) {
		cin >> cost[i];
		pa[i]=i;
		cp[i] = cost[i];
	}
	for(int i=0;i<k;i++) {
		int s,a,b;
		cin >> s >> a;
		a--;
		s--;
		while(s--) {
			cin >> b;
			b--;
			merge(a,b);
		}
	}
	long long ans=0;
	for(int i=0;i<m;i++) {
		string s;
		cin >> s;
		ans += cp[find(tr[s])];
	}
	cout << ans;
	return 0;
}