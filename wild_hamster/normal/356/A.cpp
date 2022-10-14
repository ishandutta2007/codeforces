#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
set <ll> f;
set <ll>::iterator itl,itr,it;
vector <ll> tmp;
ll i,j,m,n,k1,k2,l,r,x,a[500500];
int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        f.insert(i);
    for (i = 0; i < m; i++)
    {
        cin >> k1 >> k2 >> x;
        itl = f.lower_bound(k1);
        itr = f.upper_bound(k2);
        for (it = itl; it != itr; it++)
        {
            a[*it] = x;
            tmp.push_back(*it);
        }
        for (j = 0; j < tmp.size(); j++)
            f.erase(tmp[j]);
        tmp.clear();
        a[x] = 0;
        f.insert(x);
    }
    for (i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}