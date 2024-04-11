#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair < LL, LL > PLL;
typedef priority_queue < PLL, vector < PLL >, greater < PLL > > priorytet;

const int N = 2e5 + 7;

int n, k, m, gdzie[N];
priorytet Q[N], zajety;
map < int, int > S;

void dodaj(PLL x)
{
	Q[gdzie[x.second]].push({x.first, x.second});
	S[gdzie[x.second]]++;
	zajety.pop();
}

// ((gdzie, (kiedy, indeks))
pair < LL, PLL > cmp(pair < LL, PLL > aa, pair < LL, PLL > bb, LL xx)
{
	if(abs(aa.first - xx) == abs(bb.first - xx))
	{
		if(aa.second <= bb.second) return aa;
		return bb;	
	}
	else if(abs(aa.first - xx) < abs(bb.first - xx))
		return aa;
	return bb;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k >> m;
	for(int i = 1; i <= k; i++)
	{
		int x; cin >> x;
		S[x]++;
		Q[x].push({0, i});
	}
	// Q[x] - (kiedy, indeks)
	// zajety - (kiedy, indeks)
	for(int i = 0; i < m; i++)
	{
		LL t; int a, b;
		cin >> t >> a >> b;
		while(!zajety.empty() && zajety.top().first <= t)
		{
			dodaj(zajety.top());
		} 
		if(S.empty())
		{
			auto x = zajety.top(), y = x;
			while(!zajety.empty() && y.first == x.first)
			{
				dodaj(y);
				if(!zajety.empty()) y = zajety.top();
			}
		}
		assert(!S.empty());
		pair < LL, PLL > tmp = {1e9 + 7, {0, 0}};
		if(!Q[a].empty())
		{
			tmp = {a, Q[a].top()};
		}
		else
		{
			auto it = S.lower_bound(a);
			if(it != S.end()) tmp = cmp(tmp, {it->first, Q[it->first].top()}, a);
			if(it != S.begin())
			{
				it--;
				tmp = cmp(tmp, {it->first, Q[it->first].top()}, a);
			}
		}
		LL czas = abs(LL(a) - tmp.first) + max(0LL, tmp.second.first - t);
		cout << tmp.second.second << " " << czas << "\n";
		
		zajety.push({t + czas + abs(LL(b) - LL(a)), tmp.second.second});
		gdzie[tmp.second.second] = b;
		Q[tmp.first].pop();
		S[tmp.first]--;
		if(S[tmp.first] == 0) S.erase(tmp.first);
	}
	return 0;
}