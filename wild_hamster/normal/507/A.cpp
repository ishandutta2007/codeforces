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
ll q,n,i,j,k1,k2,k3,d,x,k,y,m,l,r,c,t,sum,a[100500];
pair <ll,ll> dniwe[100500];
vector <ll> rez;
int main()
{
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> dniwe[i].first;
        dniwe[i].second = i+1;
    }
    sort(dniwe,dniwe+n);
    sum = 0;
    i = 0;
    while (sum+dniwe[i].first <= k && i < n)
    {
          sum += dniwe[i].first;
          rez.push_back(dniwe[i].second);
          i++;
    }
    cout << rez.size() << endl;
    for (i = 0; i < rez.size(); i++)
        cout << rez[i] << " ";
    return 0;
}