#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
struct stud
{
	ll skill,price,number;
};
class comp
{
	public:
	bool operator()(stud x, stud y)
	{
		if (x.price > y.price)
			return true;
		return false;
	}
};
bool ff(stud x, stud y)
{
	if (x.skill < y.skill) return true;
	if (x.skill > y.skill) return false;
	if (x.price < y.price) return true;
	return false;
}
stud p[100500];
priority_queue<stud, vector<stud>, comp> pq;
ll n,m,s,i,j,rez[100500];
pair <ll,ll> a[100500];
int main()
{
	cin >> n >> m >> s;
	for (i = 0; i < m; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	for (i = 0; i < n; i++)
	{
		cin >> p[i].skill;
	}
	for (i = 0; i < n; i++)
	{
		cin >> p[i].price;
		p[i].number = i;
	}
	sort(p,p+n,ff);
	sort(a,a+m);
	ll l = 1, r = m+1;
	while (l < r)
	{
		ll mid = (l+r-1)/2;
		ll flag = 1;
		ll tmp = m -1;
		j = n - 1;		
		ll sum = 0;
		while (tmp >= 0)
		{
			while (p[j].skill >= a[tmp].first && j>=0)
			{
				pq.push(p[j]);
				j--;
			}
			if (pq.empty())
			{
				flag = 0;
				break;
			} else
			{
				sum += pq.top().price;
				pq.pop();
			}
			tmp -= mid;
		}
		if (flag == 1&&sum <= s)
			r = mid;
		else
			l = mid + 1;
		while (!pq.empty())
			pq.pop();
	}
	if (l == m+1)
	{
		cout << "NO" << endl;
		return 0;
	}
	ll tmp = m - 1;
	j = n - 1;
	while (tmp >= 0)
	{
		while (p[j].skill >= a[tmp].first && j >= 0)
		{
			pq.push(p[j]);
			j--;
		}
		stud rak = pq.top();
		pq.pop();
		tmp -= l;
		for (i = max(tmp+1,0LL); i <= tmp + l; i++)
			rez[a[i].second] = rak.number+1;
	}
	cout << "YES" << endl;
	for (i = 0; i < m; i++)
		cout << rez[i] << " ";
	cout << endl;
	//cout << l << endl;
	return 0;
}