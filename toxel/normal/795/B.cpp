#include<bits/stdc++.h>

#define ll long long

const int N = 100010;

std::pair <ll, ll> phy[N], inf[N], prephy[N], preinf[N];
int n, m, d;

int main(){
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1, x, y; i <= n; ++ i){
		scanf("%d%d", &x, &y);
		phy[i] = {-x, y};
	}
	std::sort(phy + 1, phy + n + 1);
	for (int i = 1; i <= n; ++ i){
		prephy[i] = {prephy[i - 1].first - phy[i].first, prephy[i - 1].second + phy[i].second};
	}
	for (int i = 1, x, y; i <= m; ++ i){
		scanf("%d%d", &x, &y);
		inf[i] = {-x, y};
	}
	std::sort(inf + 1, inf + m + 1);
	for (int i = 1; i <= m; ++ i){
		preinf[i] = {preinf[i - 1].first - inf[i].first, preinf[i - 1].second + inf[i].second};
	}
	ll max = 0;
	for (int i = 1, j = m; i <= n; ++ i){
		while (j && prephy[i].second + preinf[j].second > d){
			-- j;
		}
		if (!j){
			break;
		}
		max = std::max(max, prephy[i].first + preinf[j].first);
	}
	return printf("%I64d\n", max), 0;
}