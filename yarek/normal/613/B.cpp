#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

pair<int, int> a[1000000];
long long sum[1000000];
int res[1000000];

#undef int
int main()
{
#define int long long
    ios_base::sync_with_stdio(0);
    int n, cf, cm;
    long long m, A;
    cin >> n >> A >> cf >> cm >> m;
    for(int i = 1; i <= n; i++)
    {
	cin >> a[i].first;
	a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
	sum[i] = sum[i-1] + a[i].first;
    pair<long long, pair<int, int> > ans = make_pair(0LL, make_pair(0, 0));
    int j = n;
    for(int i = 0; i <= n; i++)
    {
	long long d = m - i * A + sum[n] - sum[n - i];
	if(d < 0) break;
	j = min(j, n - i);
	while(j > 1 && d < j * a[j].first - sum[j]) j--;
	d -= j * a[j].first - sum[j];
	int k = min(A, i == n ? A : (a[j].first + d / j));
	ans = max(ans, make_pair(i * cf + (long long)k * cm, make_pair(i, k)));
    }
    for(int i = 0; i < ans.second.first; i++)
	a[n - i].first = A;
    for(int i = 1; i <= n; i++)
    {
	a[i].first = max(a[i].first, ans.second.second);
	res[a[i].second] = a[i].first;
    }
    cout << ans.first << "\n";
    for(int i = 1; i <= n; i++)
	cout << res[i] << " ";
    cout << endl;
}