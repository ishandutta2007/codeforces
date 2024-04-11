#include <iostream>
#include <cstdio>
#include <set>
#define ll long long
#define maxn 200005
using namespace std;
int n;
ll a[maxn];
set<pair<ll, ll> > pos;
set<pair<ll, ll> >::iterator it, it2, it3;
inline void ins(ll a, ll b)
{
	it2 = pos.lower_bound(make_pair(a, 0));
	//printf("%lld %lld %lld %lld\n", a, b, (*it2).first, (*it2).second);
	if((*it2).second >= b) return;
	if((*it2).first == a)
	{
		it3 = it2; it2--;
		pos.erase(it3);
	}
	else it2--;
	for (; it2 != pos.begin(); it2 = it3)
	{
		it3 = it2; it3--;
		if((*it2).second <= b) pos.erase(it2);
		else break;
	}
	pos.insert(make_pair(a, b));
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	pos.insert(make_pair(a[1] - 1, 0));
	pos.insert(make_pair(-1, 3e18));
	for (int i = 2; i <= n; i++)
	{
		if(a[i] > a[i - 1]) {a[i] = a[i - 1]; continue;}
		it = pos.lower_bound(make_pair(a[i], 0));
		it2 = it; it2--;
		if((*it2).first != a[i] - 1) pos.insert(make_pair(a[i] - 1, (*it).second));
		if((a[i - 1] - 1) / a[i] < 2)
		{
			for (; it != pos.end(); it = it2) 
			{
				//printf("!!! %lld %lld\n", (*it).first, (*it).second); 
				ins((*it).first - a[i], (*it).second + a[i] * (i - 1));
				it2 = it; it2++;
				pos.erase(it);
			}
		}
		else
		{
			it = pos.end(); it--;
			for (; (*it).first >= a[i]; it = it2)
			{
				ins((*it).first % a[i], (*it).second + ((*it).first / a[i]) * a[i] * (i - 1));
				ins(a[i] - 1, (*it).second + ((*it).first / a[i] - 1) * a[i] * (i - 1));
				it2 = it; it2--;
				pos.erase(it);
			}
		}
		//printf("%lld: \n", a[i]);
		//for (it = pos.begin(); it != pos.end(); it++) printf("%lld %lld\n", (*it).first, (*it).second);
	}
	ll ans = 0;
	for (it = pos.begin(), it++; it != pos.end(); it++) ans = max(ans, (*it).first * n + (*it).second);
	printf("%lld", ans);
	return 0;
}