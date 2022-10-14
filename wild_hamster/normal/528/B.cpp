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
#define MOD 1000000009
typedef long long ll;
using namespace std;
ll h,x,y,w,l,wl,wr,hl,hr,r,i,j,n,k,k1,k2,d,m,q,max1,amnt,a[200500],b[200500];
char c;
multiset <pair<ll,ll> > prs,iprs;
multiset <pair<ll,ll> >::iterator itr,itr1;
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        prs.insert(mp(x+y,x-y));
        iprs.insert(mp(x-y,x+y));
    }
    ll rez = 0;
    while (!prs.empty())
    {
    itr = prs.begin();
    l = (*itr).second;
    r = (*itr).first;
    //cout << l << " " << r << endl;
    prs.erase(itr);
    itr = iprs.find(mp(l,r));
    iprs.erase(itr);
    while ((*iprs.begin()).first < r && !iprs.empty())
    {
     itr = iprs.begin();
     x = (*itr).first; y = (*itr).second;
     iprs.erase(itr);
     itr = prs.find(mp(y,x));
     prs.erase(itr);
    }
    rez++;
    }
    cout << rez << endl;
    return 0;
}