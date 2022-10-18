#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pob pop_back
#define mp make_pair
#define pque priority queue

const ll mod = 1e9 + 7, inf = 1e18 + 5;
const int N = 1e5 + 5, MAX = 1e5 + 10, MAXX = 1e5 + 1;
int a[N], cnt[MAX], mobius[MAX];
ll x, n, sz, sum = 0;
vector <int> divi[MAX];

void sieve(){
	for (int i = 1; i <= MAXX; i++){
		for (int j = i; j <= MAXX; j += i){
			divi[j].push_back(i);
		}
	}
}

ll power(ll x, ll y){
	ll temp;
	if (y == 0){
		return 1;
	}
	temp = power(x, y / 2);
	if (y % 2){
		return ((x * temp) % mod * temp) % mod;
	}
	return (temp * temp) % mod;
}
 
void getmobius(int x){
	int s = sqrt(x);
	for (int i = 1; i <= x; i++){
		mobius[i] = 1;
	}
	for (int i = 2; i <= s; i++){
		if (mobius[i] == 1){
			for (int j = i; j <= x; j += i){
				mobius[j] *= -i;
			}
			for (int j = i * i; j <= x; j += i * i){
				mobius[j] = 0;
			}
		}
	}
	for (int i = 2; i <= x; i++){
		if (mobius[i] == i){
			mobius[i] = 1;
		}
		else if (mobius[i] == -i){
			mobius[i] = -1;
		}
		else if (mobius[i] < 0){
			mobius[i] = 1;
		}
		else if (mobius[i] > 0){
			mobius[i] = -1;
		}
	}
	return;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	getmobius(MAXX);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sz = divi[a[i]].size();
		for (int j = 0; j < sz; j++){
			cnt[divi[a[i]][j]]++;
		}
	}
	for (int i = 1; i <= MAXX; i++){
		if (cnt[i] == 0){
			continue;
		}
		x = (power(2, cnt[i]) - 1) % mod;
		sum += (mobius[i] * x) % mod;
		//cout << sum << " ";
		sum %= mod;
		if (sum < 0){
			sum += mod;
		}
	}
	if (sum < 0){
		sum += mod;
	}
	cout << sum;
}