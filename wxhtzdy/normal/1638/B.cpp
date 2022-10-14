#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, p[100005];
vector<int> v[2];

bool is_sorted(vector<int> a)
{
	rep1(i, a.size() - 1) if(a[i] < a[i - 1]) return false;
	return true;
}

void solve() 
{
	scanf("%d", &n);
	v[0].clear(); v[1].clear();
	rep1(i, n) scanf("%d", &p[i]), v[p[i] & 1].push_back(p[i]);
	puts(is_sorted(v[0]) && is_sorted(v[1]) ? "YES" : "NO");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();	
	return 0;
}