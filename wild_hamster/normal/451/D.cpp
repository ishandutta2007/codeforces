#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll m,i,n,k,j,a[300500],b[300500],t,x,y,z,d1,d2,rez,as,bs,odds,evens;
pair <ll,ll> aoe[100500],boe[100500];
string s;
int main()
{
    cin >> s;
    as = bs = 0;
    for (i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
               a[as++] = i;
            else b[bs++] = i;
        }
    aoe[as-1].first = a[as-1]%2; aoe[as-1].second = (a[as-1]+1)%2; 
    boe[bs-1].first = b[bs-1]%2; boe[bs-1].second = (b[bs-1]+1)%2; 
    for (i = as-2; i >= 0; i--)
    {
        aoe[i].first = aoe[i+1].first + a[i]%2;
        aoe[i].second = aoe[i+1].second + (a[i]+1)%2; 
    }
    
    for (i = bs-2; i >= 0; i--)
    {
        boe[i].first = boe[i+1].first + b[i]%2;
        boe[i].second = boe[i+1].second + (b[i]+1)%2; 
    }
    odds = evens = 0;
    for (i = 0; i < as; i++)
    {
        evens += (a[i]%2)*aoe[i].first + ((a[i]+1)%2)*aoe[i].second;
        odds += ((a[i]+1)%2)*aoe[i].first + (a[i]%2)*aoe[i].second;
    }
    
    for (i = 0; i < bs; i++)
    {
        evens += (b[i]%2)*boe[i].first + ((b[i]+1)%2)*boe[i].second;
        odds += ((b[i]+1)%2)*boe[i].first + (b[i]%2)*boe[i].second;
    }
    cout << odds << " " << evens << endl;
    return 0;
}