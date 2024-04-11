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
string s;
ll n,i,j,k1,k2,x,k,y,m,l,r,c,t,sum,xors[100500];
ll gcd(ll a, ll b)
{
          if (a%b == 0) return b;
          else
          return gcd(b,a%b);
}
map <string, string> lalka;
map <string, string>::iterator itr;
string s1,s2;
vector <pair<string,string> > rez;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        if (lalka.find(s1) == lalka.end())
        {
         lalka[s2] = s1;
        }
        else
        {
            lalka[s2] = lalka[s1];
            lalka.erase(s1);
        }
    }
    for (itr = lalka.begin(); itr != lalka.end(); itr++)
    {
        rez.push_back(mp((*itr).second,(*itr).first));
    }
    cout << rez.size() << endl;
    for (i = 0; i < rez.size(); i++)
        cout << rez[i].first << " " << rez[i].second << endl;
    return 0;
}