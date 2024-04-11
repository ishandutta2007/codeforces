#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 500;

struct BIT{
	int fenw[N];
	BIT(int _N){ for(int i = 0;i < _N;i++) fenw[i] = 0; }
	void Update(int x){
		for(;x < N;x += x & -x) fenw[x]++;
	}
	int Get(int x){
		int sum = 0;
		for(;x > 0;x -= x & -x) sum += fenw[x];
		return sum;
	}
};

struct Compress{
	vector<int> xs;
	void Add(int x){ xs.push_back(x); }
	void Build(){ sort(xs.begin(), xs.end()); xs.erase(unique(xs.begin(), xs.end()), xs.end()); }
	int Get(int x){ return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1; }
};

int A[N], n;

void solve(){
	scanf("%d", &n);
	Compress CPR;
	for(int i = 0;i < n;i++) scanf("%d", &A[i]), CPR.Add(A[i]);
	CPR.Build();
	for(int i = 0;i < n;i++) A[i] = CPR.Get(A[i]);
	long long ans = 0;
	BIT F(n + 500);
	for(int i = 0;i < n;i++){
		ans += min(F.Get(A[i] - 1), F.Get(n + 123) - F.Get(A[i]));
		F.Update(A[i]);
	}
	printf("%lld\n", ans);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}