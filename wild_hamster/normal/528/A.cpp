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
multiset <ll> ww,hh,wd,hd;
multiset <ll>::iterator itr;
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout
    cin >> w >> h >> n;
    hl = 0; hr = h;
    wl = 0; wr = w;
    ll rez = h*w;
    ww.insert(0); ww.insert(w);
    hh.insert(0); hh.insert(h);
    wd.insert(w); hd.insert(h);
    for (i = 0; i < n; i++)
    {
        cin >> c >> x;
        if (c == 'H')
        {
           itr = hh.upper_bound(x);
           r = *itr;
           itr--;
           l = *itr;
          hh.insert(x);
          itr = hd.find(r-l);
          hd.erase(itr);
          hd.insert(x-l);
          hd.insert(r-x);
        } else
        
        {
         itr = ww.upper_bound(x);
           r = *itr;
           itr--;
           l = *itr;
          ww.insert(x);
          
          itr = wd.find(r-l);
          wd.erase(itr);
          wd.insert(x-l);
          wd.insert(r-x);
        }
        ll tmp = 1;
       /* for (itr = hd.begin(); itr != hd.end(); itr++)
            cout << *itr << " ";
        cout << endl;
        
        for (itr = wd.begin(); itr != wd.end(); itr++)
            cout << *itr << " ";
        cout << endl;*/
        
        itr = hd.end();
        itr--;
        tmp *= *itr;
        itr = wd.end();
        itr--;
        tmp *= *itr;
        printf("%I64d\n",tmp);
    }
    return 0;
}