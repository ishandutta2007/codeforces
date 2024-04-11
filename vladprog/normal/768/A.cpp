#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    multiset<int> m;
    while(n--)
    {
        int t;
        cin>>t;
        m.insert(t);
    }
    m.erase(*m.begin());
    if(!m.empty())
    {
        multiset<int>::iterator it=m.end();
        it--;
        m.erase(*it);
    }
    cout<<m.size();
}