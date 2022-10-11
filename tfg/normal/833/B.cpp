#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

using namespace std;
typedef long long ll;
const int ms = 35011;

int v[ms], memo[55][ms];
int cnt[ms], step;

namespace count{
	int l = 0, r = 0;
	int freq[ms] = {0};
	int ans = 0;
	int query(int le, int ri){
		ri++;
		while(r < ri){
			freq[v[r]]++;
			if(freq[v[r]] == 1)
				++ans;
			r++;
		}
		while(l > le){
			l--;
			freq[v[l]]++;
			if(freq[v[l]] == 1)
				++ans;
		}
		while(r > ri){
			r--;
			freq[v[r]]--;
			if(freq[v[r]] == 0)
				--ans;
		}
		while(l < le){
			freq[v[l]]--;
			if(freq[v[l]] == 0)
				--ans;
			++l;
		}
		return ans;
	}
}

void go(int l, int r, int a, int b, int k){
	if(l > r){
		return;
	}
	int m = (l + r)/2;
	int aa = max(m, a);
	int best = aa, val = count::query(m, aa) + memo[k-1][aa+1];
	fr(i, aa+1, b+1){
		int aux = count::query(m, i) + memo[k-1][i+1];
		if(aux > val){
			val = aux;
			best = i;
		}
	}
	memo[k][m] = val;
	go(l, m-1, a, best, k);
	go(m+1, r, best, b, k);
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	fr(i, 0, n)
		cin >> v[i];
	fr(i, 0, n){
		memo[1][i] = count::query(i, n-1);
	}
	fr(i, 2, k+1){
		go(0, n-1, 0, n-1, i);
	}
	printf("%d\n", memo[k][0]);
	return 0;
}