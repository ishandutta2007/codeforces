#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, m, v[305], u[305], w[305], cl[1000005], cr[1000005], rt[305];
LL mst[1000005];
vector<int> vec;

int root(int x)
{
	return rt[x] == x ? x : rt[x] = root(rt[x]);
}

LL calc(int q) 
{
	int id = lower_bound(vec.begin(), vec.end(), q + 1) - vec.begin() - 1;
	while(vec[id] > q) id --;
	while(vec[id + 1] <= q) id ++;
	//if(q == 7) printf("wtf %d\n", vec[id]);
	LL ret = mst[id] + (q - vec[id]) * 1LL * cl[id] - (q - vec[id]) * 1LL * cr[id];
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	rep1(i, m) scanf("%d%d%d", &v[i], &u[i], &w[i]);
	rep1(i, m) rep1(j, m) vec.push_back((w[i] + w[j]) / 2);
	rep1(i, m) rep1(j, m) vec.push_back((w[i] + w[j] + 1) / 2);
	rep1(i, m) rep1(j, m) vec.push_back((w[i] + w[j] - 1) / 2);	
	rep1(i, m) rep1(j, m) vec.push_back((w[i] + w[j] + 2) / 2);	
	rep1(i, m) rep1(j, m) vec.push_back((w[i] + w[j] - 2) / 2);
	vec.push_back(0);
	vec.push_back(1e8);
	vec.push_back(1e8 + 1);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	rep(i, vec.size()) {
		int x = vec[i];
		//printf("! %d\n", x);
		PII ord[305];
		rep1(j, m) ord[j] = MP(abs(w[j] - x), j);
		sort(ord + 1, ord + m + 1);
		rep1(j, n) rt[j] = j;
		rep1(j, m) {
			int id = ord[j].second;
			if(root(u[id]) != root(v[id])) {
				rt[root(u[id])] = root(v[id]);
				//if(vec[i] == 6) printf("%d %d %d\n", u[id], v[id], w[id]);
				(w[id] <= vec[i] ? cl[i] : cr[i]) ++;
				mst[i] += abs(x - w[id]);
			}
		}
	}
	
	int p, k, a, b, c;
	scanf("%d%d%d%d%d", &p, &k, &a, &b, &c);
	k = k - p;
	int q;
	LL ans = 0;
	//printf("??? %lld\n ???", calc(7));
	while(p --) {
		scanf("%d", &q);
		ans ^= calc(q);
		//printf("%lld\n", calc(q));
	}
	while(k --) {
		q = (q * 1LL * a + b) % c;
		ans ^= calc(q);
		//printf("%lld\n", calc(q));
	}
	printf("%lld", ans);
	return 0;
}