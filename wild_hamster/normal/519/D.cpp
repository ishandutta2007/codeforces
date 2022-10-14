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
ll x,y,l,r,i,j,n,k,k1,k2,d,m,a[1005],b[100500],c[100500],q,dr;
map <ll,ll> lalka;
map <ll,ll>::iterator itr;
vector <ll> letters[300];
string s;
int main()
{
    for (i = 'a'; i <= 'z'; i++)
        cin >> a[i];
    cin >> s;
    b[0] = 0;
    n = s.size();
    for (i = 0; i < n; i++)
    {
        b[i+1] = b[i] + a[s[i]];
        letters[s[i]].push_back(i);
    }
    
     
     ll rez = 0;   
    for (i = 'a'; i <= 'z'; i++)
    {
     m = letters[i].size();
     c[0] = 0;
     lalka.clear();
     lalka[0]++;
     for (j = 0; j < m-1; j++)
     {
      c[j+1] = c[j] + b[letters[i][j+1]+1]-b[letters[i][j]+1];
      lalka[c[j+1]]++;
     }
     
     for (j = 0; j <= m-1; j++)
     {
         lalka[c[j]]--;
         rez += lalka[ c[j] + a[i] ];
     }
     
    }
    cout << rez << endl;
    return 0;
}