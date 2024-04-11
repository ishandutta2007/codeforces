#include <iostream>
#include <cmath>
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
ll x,y,n,m,q,i,j,k,k1,k2,l,a[1000500];
vector <pair <ll,ll> > rez;
ll ones[300500],twos[300500];
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1) k1++;
           else k2++;
    }
    if (n == 1)
    {
          cout << 1 << endl << 1 << " " << 1 << endl;
          return 0;
    }
    //rez.push_back(mp(1,k1));
    ll tmp1 = 1, tmp2 = 1;
    for (i = 0; i < 300000; i++)
        ones[i] = twos[i] = tr;
    ones[0] = twos[0] = -1;
    for (i = 0; i < n; i++)
        if (a[i] == 1) ones[tmp1++] = i;
           else twos[tmp2++] = i;
    for (i = max(k1,k2); i >= 1; i--)
    {
        //cout << i << endl;
        ll l1 = 0, l2 = 0;
        j = -1;
        //cout << j << endl;
        ll flag = 1;
        ll tmp = 1;
        ll wins1 = 0, wins2 = 0;
        ll lastwin;
        while (j < n-1)
        {
              //cout << j << "  "<< l1 << " " << l2 << endl;
              //system("pause");
              if (ones[l1+i] == tr && twos[l2+i] == tr)
              {
                 flag = 0;
                 break;
              }
              if (ones[l1+i] < twos[l2+i])
              {
               wins1++;
               lastwin = 1;
               j = ones[l1+i];
               l2 = upper_bound(twos,twos+n,j)-twos-1;
               l1 += i;
              } else
              {
               wins2++;
               lastwin = 2;
               j = twos[l2+i];
               l1 = upper_bound(ones,ones+n,j)-ones-1;
               l2 += i;
              }
        }
        if (!flag||wins1 == wins2||(wins1 > wins2&&lastwin == 2)||(wins2 > wins1&&lastwin == 1)) continue;
           else rez.push_back(mp(max(wins1,wins2),i));
        //j = ones[i];
    }    
    //rez.push_back(mp(k1,1));
    sort(rez.begin(),rez.end());
    cout << rez.size() << endl;
    for (i = 0; i < rez.size(); i++)
        cout << rez[i].first << " " << rez[i].second << endl;
	return 0;
}