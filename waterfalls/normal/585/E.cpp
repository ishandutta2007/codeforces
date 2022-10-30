#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

bool prime[10000013];
int low[10000013];
int two[500013];

void make() {
	memset(prime,1,sizeof prime);
	prime[0] = prime[1] = 0;
	for (int i=2;i<10000013;i++) if (prime[i]) {
		low[i] = i;
		for (int j=i+i;j<10000013;j+=i) {
			if (prime[j]) low[j] = i;
			prime[j] = 0;
		}
	}
	two[0] = 1;
	for (int i=1;i<500013;i++) {
		two[i] = two[i-1]*2;
		if (two[i]>=MOD) two[i]-=MOD;
	}
}

vector<pair<int,int> > factor(int a) {
	vector<pair<int,int> > factors;
	while (a>1) {
		int cur = low[a];
		int num = 0;
		while (low[a]==cur) {
			a/=cur;
			num+=1;
		}
		factors.push_back(make_pair(cur,num));
	}
	return factors;
}

int n;
int cnt[10000013];
int tot[10000013];

void recur(int cur, int on, vector<pair<int,int> >& factors) {
	if (on==factors.size()) cnt[cur]+=1;
	else {
		for (int i=0;i<=factors[on].second;i++) {
			recur(cur,on+1,factors);
			cur*=factors[on].first;
		}
	}
}

void add(int a) {
	auto factors = factor(a);
	recur(1,0,factors);
}

int recur2(int cur, int on, int par, vector<pair<int,int> >& factors) {
	if (on==factors.size()) return par*cnt[cur];
	else {
		return recur2(cur,on+1,par,factors)
			  +recur2(cur*factors[on].first,on+1,-par,factors);
	}
}

int get(int a) {
	auto factors = factor(a);
	return recur2(1,0,1,factors);
}

int main() {
	make();
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		add(a);
	}
	int ans = 0;
	for (int i=10000012;i>1;i--) {
		tot[i] = two[cnt[i]]-1;
		if (tot[i]<0) cnt[i]+=MOD;
		if (!tot[i]) continue;
		for (int j=i+i;j<10000013;j+=i) {
			tot[i]-=tot[j];
			if (tot[i]<0) tot[i]+=MOD;
		}
		int num = get(i);
		ans = (ans+(long long) tot[i]*num)%MOD;
	}
	printf("%d\n",ans);

	return 0;
}