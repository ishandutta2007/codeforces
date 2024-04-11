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
ll x,y,l,r,i,j,n,k,k1,k2,d,m,a[100500],b[100500],q,dr;
map <ll,ll> lalka;
map <ll,ll>::iterator itr;
ll black,white;
char c;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        lalka[x]++;
    }
    
    for (i = 0; i < n-1; i++)
    {
        cin >> a[i];
        x = a[i];
        lalka[x]--;
        if (lalka[x] == 0)
           lalka.erase(x);
    }
    itr = lalka.begin();
    cout << (*itr).first << endl;
    
    lalka.clear();
    
    for (i = 0; i < n-1; i++)
        lalka[a[i]]++;
    
    for (i = 0; i < n-2; i++)
    {
        cin >> x;
        lalka[x]--;
        if (lalka[x] == 0)
           lalka.erase(x);
    }
    
    itr = lalka.begin();
    cout << (*itr).first << endl;
    
    lalka.clear();
    return 0;
}