#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<pair<long long, long long> > vec;

unordered_map<long long, vec> m;
vec divv;
const long long inf = 1000000000000000000LL;

long long base[1000001];
bool np[1000001];

long long getBase(long long k)
{
//     if(k <= 1) return -1;
    if(k <= 1000000)
  	return base[k];
    for(long long i = 2; i * i <= k; i++)
	if(k % i == 0)
	{
	    long long a = i;
	    while(a < k) a *= i;
	    if(a == k) return i;
	    return -1;
	}
    return k;
}

long long algo(long long k, long long min)
{
//     cout << "algo " << k << " " << min << endl;
    if(k == 1) return 1;
    if(m.count(k))
    {
	vec &v = m[k];
	vec::iterator it = lower_bound(v.begin(), v.end(), make_pair(min, 0LL));
	long long ans = (--it)->second;
// 	cout << ans << endl;
	return ans;
    }
    vec &v = m[k];
    v.push_back(make_pair(0, 0));
    for(auto d: divv)
    {
	if(d.first > k) break;
	if(k % d.first) continue;
	v.push_back(make_pair(d.second, algo(k / d.first, d.second)));
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < v.size(); i++)
	v[i].second += v[i-1].second;
//      cout << k << endl;
//      for(int i = 0; i < v.size(); i++)
//  	cout << v[i].first << " " << v[i].second << endl;
//      cout << endl;
    vec::iterator it = lower_bound(v.begin(), v.end(), make_pair(min, 0LL));
    long long ans = (--it)->second;
//     cout << ans << " " << it->first << endl;
    return ans;
}

int main()
{
    for(int i = 0; i <= 1000000; i++)
	base[i] = -1;
    for(int i = 2; i <= 1000000; i++)
	if(!np[i])
	{
	    for(long long j = (long long)i * i; j <= 1000000; j += i)
		np[j] = true;
	    for(long long j = i; j <= 1000000; j *= i)
		base[j] = i;
	}
    ios_base::sync_with_stdio(0);
    long long a;
    cin >> a;
    for(long long i = 1; i * i <= a; i++)
	if(a % i == 0)
	{
	    long long b = getBase(i - 1);
	    if(b != -1) divv.push_back(make_pair(i, b));
	    if(i * i == a) continue;
	    long long k = a / i;
	    b = getBase(k - 1);
	    if(b != -1) divv.push_back(make_pair(k, b));
	}
    sort(divv.begin(), divv.end());
    cout << algo(a, inf);
}