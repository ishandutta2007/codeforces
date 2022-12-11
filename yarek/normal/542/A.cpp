#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct s
{
    int a, b, c, nr;
    s(int A = 0, int B = 0, int C = 0, int Nr = 0) : a(A), b(B), c(C), nr(Nr) { }
};

const int offset = 1 << 20;
pair<int, int> tab[offset << 1];

void insert(int a, pair<int, int> b)
{
    a += offset;
    while(a > 0)
    {
	tab[a] = max(tab[a], b);
	a >>= 1;
    }
}

pair<int, int> answer(int a, int b)
{
    a += offset; b += offset;
    pair<int, int> ans(0, 0);
    while(a < b)
    {
	if(a & 1) ans = max(ans, tab[a++]);
	if((b & 1) == 0) ans = max(ans, tab[b--]);
	a >>= 1;
	b >>= 1;
    }
    if(a == b) ans = max(ans, tab[a]);
    return ans;
}

vector<int> x;

int pos(int k)
{
    return lower_bound(x.begin(), x.end(), k) - x.begin();
}

bool cmp1(s a, s b)
{
    return make_pair(a.a, a.c) < make_pair(b.a, b.c);
}

bool cmp2(s a, s b)
{
    return make_pair(-a.b, a.c) < make_pair(-b.b, b.c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, a, b, c;
    pair<long long, pair<int, int> > ans(0, make_pair(0, 0));
    vector<s> vec;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
	cin >> a >> b;
	x.push_back(a);
	x.push_back(b);
	vec.push_back(s(a, b, 0, i));
    }
    for(int i = 0; i < m; i++)
    {
	cin >> a >> b >> c;
	x.push_back(a);
	x.push_back(b);
	vec.push_back(s(a, b, c, i));
    }
    sort(vec.begin(), vec.end(), cmp1);
    sort(x.begin(), x.end());
    pair<int, int> fur(0, 0);
    for(int i = 0; i < vec.size(); i++)
    {
	s p = vec[i];
	if(p.c == 0) fur = max(fur, make_pair(p.b, p.nr));
	else ans = max(ans, make_pair((long long)p.c * (min(fur.first, p.b) - p.a), make_pair(p.nr, fur.second)));
    }
    for(int i = vec.size() - 1; i >= 0; i--)
    {
	s p = vec[i];
	if(p.c == 0) insert(pos(p.b), make_pair(p.b - p.a, p.nr));
	else
	{
	    pair<int, int> an = answer(0, pos(p.b));
	    ans = max(ans, make_pair((long long)p.c * an.first, make_pair(p.nr, an.second)));
	}
    }
    sort(vec.begin(), vec.end(), cmp2);
    fur.first = 1000000000;
    for(int i = 0; i < vec.size(); i++)
    {
	s p = vec[i];
	if(p.c == 0) fur = min(fur, make_pair(p.a, p.nr));
	else ans = max(ans, make_pair((long long)p.c * (p.b - max(fur.first, p.a)), make_pair(p.nr, fur.second)));
    }
    cout << ans.first << endl;
    if(ans.first)
	cout << (ans.second.second + 1) << " " << (ans.second.first + 1) << endl;
}