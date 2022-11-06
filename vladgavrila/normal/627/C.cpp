#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define maxn 200010

int d, n, m;
set<int> g;
pair<int, int> v[maxn];
long long sol;

int main()
{
    cin>>d>>n>>m;

    g.insert(0);
    g.insert(d);

    for(int i=1; i<=m; ++i)
        cin>>v[i].second>>v[i].first;

    sort(v+1, v+m+1);

    for(int i=1; i<=m; ++i)
    {
        set<int> :: iterator x = g.lower_bound(v[i].second);
        set<int> :: iterator y = g.lower_bound(v[i].second);
        --x;

        int nextStop = min((*x)+n, *y);

        sol += 1LL*(min(n, (*y)-v[i].second) - max(0, (nextStop-v[i].second)))*v[i].first;

        g.insert(v[i].second);
    }

    set<int> :: iterator it = g.begin();
    set<int> :: iterator it2 = g.begin();
    ++it2;

    while(it2!=g.end())
    {
        if((*it2)-(*it)>n)
        {
            cout<<"-1\n";
            return 0;
        }
        ++it;
        ++it2;
    }

    cout<<sol<<"\n";

    return 0;
}