#include<bits/stdc++.h>

#define ll long long

const int N = 100010;

ll n, q;
ll power[N];
char s[N];
int depth;

std::pair <int, int> find(ll u){
	ll value = power[depth] >> 1;
	int dep = depth - 1, sit = 0;
	while (value != u){
		if (value < u){
			sit = 1;
			value += power[-- dep];
		}
		else{
			sit = 0;
			value -= power[-- dep];
		}
	}
	return {dep, sit};
}

int main(){
	power[0] = 1;
	for (int i = 1; i < 62; ++ i){
		power[i] = power[i - 1] * 2;
	}
	scanf("%I64d%I64d", &n, &q);
	for (int i = 0; i < N; ++ i){
		if (power[i] == n + 1){
			depth = i;
			break;
		}
	}
	while (q --){
		ll u;
		scanf("%I64d%s", &u, s);
		std::pair <int, int> now = find(u);
		int len = strlen(s);
		for (int i = 0; i < len; ++ i){
			if (s[i] == 'U'){
				if (now.first == depth - 1){
					continue;
				}
				if (now.second){
					u -= power[now.first];
				}
				else{
					u += power[now.first];
				}
				now = find(u);
				continue;
			}
			if (!now.first){
				continue;
			}
			if(s[i] == 'L'){
				u -= power[now.first - 1];
			}
			else{
				u += power[now.first - 1];
			}
			now = find(u);
		}
		printf("%I64d\n", u);
	}
	return 0;
}