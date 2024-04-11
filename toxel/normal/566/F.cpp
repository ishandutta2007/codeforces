#include<bits/stdc++.h>

const int N = 1000010;

template <class T> void readin(T& x,bool mark=0){char tt=getchar();for(;tt<'0'||'9'<tt;tt=getchar()) if(tt=='-') mark=1;for(x=0;'0'<=tt&&tt<='9';x=(x<<1)+(x<<3)+tt-'0',tt=getchar());x=mark?-x:x;}

int n, a[N], min[N], dp[N];
int Hash[N];
std::vector <int> prime, fact[N];

int main(){
	readin <int> (n);
	for (int i = 1; i <= n; ++ i){
		readin <int> (a[i]);
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i){
		Hash[a[i]] = i;
	}
	for (int i = 1; i <= n; ++ i)
		dp[i] = 1;
	for (int i = 1; i <= n; ++ i){
		for (int j = 2; j * a[i] <= a[n]; ++ j){
			if (!Hash[j * a[i]])
				continue;
			dp[Hash[j * a[i]]] = std::max(dp[Hash[j * a[i]]], dp[i] + 1);
		}
	}
	int max = 0;
	for (int i = 1; i <= n; ++ i)
		max = std::max(max, dp[i]);
	printf("%d\n", max);
	return 0;
}