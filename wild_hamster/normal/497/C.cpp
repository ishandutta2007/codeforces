#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;
struct dniwe
{
       ll l, r, type, num;
};
bool ff(dniwe a, dniwe b)
{
 if (a.l < b.l) return true;
 else if (a.l > b.l) return false;
 else if (a.r > b.r) return true;
 else if (a.r < b.r) return false;
 else if (a.type < b.type) return true;
 else return false;
}
ll n,i,j,x,y,rez[100500],m;
vector <dniwe> f;
map <pair<ll,ll>, ll> lft,nums;
set <pair <ll,ll> > lalka;
set <pair <ll,ll> >::iterator itr;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        dniwe t;
        t.l = x; t.r = y; t.type = 2; t.num = i;
        f.push_back(t);
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> j;
        dniwe t;
        t.l = x; t.r = y; t.type = 1; t.num = i;
        f.push_back(t);
        lft[mp(y,i)] = j;
        nums[mp(y,i)] = i;
    }
    sort(f.begin(),f.end(),ff);
    ll flag = 1;
    for (i = 0; i < f.size(); i++)
    {
        if (f[i].type == 1) 
           lalka.insert(mp(f[i].r,f[i].num));
        else
        {
            itr = lalka.upper_bound(mp(f[i].r,-5));
            if (itr == lalka.end())
            {
                    flag = 0;
                    break;
            }
            pair <ll,ll>  t = *itr;
            lft[t]--;
            if (lft[t] == 0) lalka.erase(t);
            rez[f[i].num] = nums[t];
        }
    }
    if (flag == 0) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (i = 0; i < n; i++)
            cout << rez[i]+1 << " ";
        cout << endl;
    }
    return 0;
}