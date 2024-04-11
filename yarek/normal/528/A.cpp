#include <iostream>
#include <set>
using namespace std;

multiset<int> len[2];
set<int> cut[2];

void make_cut(int w, int x)
{
    set<int>::iterator it = cut[w].upper_bound(x), it2 = it--;
    int d = *it2 - *it;
    len[w].erase(len[w].find(d));
    len[w].insert(x - *it);
    len[w].insert(*it2 - x);
    cut[w].insert(x);
}

char s[2];
int main()
{
    ios_base::sync_with_stdio(0);
    int w, h, n, x;
    cin >> w >> h >> n;
    cut[0].insert(0);
    cut[0].insert(w);
    cut[1].insert(0);
    cut[1].insert(h);
    len[0].insert(w);
    len[1].insert(h);
    while(n--)
    {
	cin >> s >> x;
	make_cut(s[0] == 'H' ? 1 : 0, x);
	cout << ((long long)(*len[0].rbegin()) * (*len[1].rbegin())) << '\n';
    }
}