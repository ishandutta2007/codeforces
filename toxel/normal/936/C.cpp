#include<bits/stdc++.h>

const int N = 2010;

std::vector <int> vec[N];
char s[N], t[N];
int sit[N], p[N], aux[N];
std::vector <int> ans;

void perform(int n, int k){
	if (!k) return;
	for (int i = 0; i < n - k; ++ i){
		aux[i + k] = p[i];
	}
	for (int i = n - k; i < n; ++ i){
		aux[i - (n - k)] = p[i];
	}
	std::reverse(aux, aux + k);
	for (int i = 0; i < n; ++ i){
		p[i] = aux[i];
	}
	ans.push_back(k);
}

int find(int n, int x){
	for (int i = 0; i < n; ++ i){
		if (p[i] == x){
			return i;
		}
	}
}

int main(){
	int n;
	scanf("%d%s%s", &n, s, t);
	for (int i = 0; i < n; ++ i){
		vec[t[i]].push_back(i);
	}
	for (int i = 0; i < n; ++ i){
		if (sit[s[i]] == vec[s[i]].size()){
			puts("-1");
			return 0;
		}
		p[i] = vec[s[i]][sit[s[i]] ++];
	}
	for (int i = 0; i < n - 1; ++ i){
		int sit0 = find(n, 0), siti = find(n, i), siti1 = find(n, i + 1);
		if (sit0 < siti){
			siti = find(n, i);
			perform(n, n - siti - 1);
			siti1 = find(n, i + 1);
			perform(n, n - siti1 - 1);
			perform(n, 1);
		}
		else{
			if (siti < siti1){
				siti1 = find(n, i + 1);
				perform(n, n - siti1 - 1);
				perform(n, 1);
				siti = find(n, i);
				perform(n, n - siti);
			}
			else{
				siti1 = find(n, i + 1);
				perform(n, n - siti1 - 1);
				sit0 = find(n, 0);
				perform(n, n - sit0);
				siti = find(n, i);
				perform(n, n - siti);
			}
		}
	}
	if (p[0]){
		perform(n, n);
	}
	printf("%d\n", (int) ans.size());
	for (auto u : ans){
		printf("%d ", u);
	}
	putchar('\n');
	return 0;
}