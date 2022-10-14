#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,dr,a[100005];
map <pair<ll,ll>,ll> friends;
map <ll,vector <ll> > trfr;
vector <ll> persons;
map <ll,ll> used;
vector <ll> rez;
int main()
{
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (!used[x])
        {
         used[x] = 1;
         persons.push_back(x);
        }
        
        if (!used[y])
        {
         used[y] = 1;
         persons.push_back(y);
        }
        
        trfr[x].push_back(y);
        trfr[y].push_back(x);
        friends[mp(x,y)] = friends[mp(y,x)] = 1;
    }
    m = persons.size();
    sort(persons.begin(),persons.end());
    for (i = 0; i < m; i++)
    {
        cout << persons[i] << ": ";
        ll v = persons[i];
        rez.clear();
        for (j = 0; j < m; j++)
        if (j != i)
        {
         ll to = persons[j];
         ll sz = trfr[to].size();
         ll tmp = 0;
         for (l = 0; l < sz; l++)
         {
             ll vrt = trfr[to][l];
             if (friends[mp(vrt,v)] == 1)
                tmp++;
         }
         if (tmp*100 >= k*trfr[v].size() && friends[mp(to,v)] == 0)
            rez.push_back(to);
        }
        cout << rez.size();
        for (j = 0; j < rez.size(); j++)
            cout << " " << rez[j];
        cout << endl;
    }
    return 0;
}