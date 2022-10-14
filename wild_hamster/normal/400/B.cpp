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
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll i,j,n,l,r,rez,k,m,y,z,q,x,a[100500],next;
vector <ll> f;
string s;
int main()
{
    cin >> n >> m;
    rez = 0;
    ll flag = 0;
    for (j = 0; j < n; j++)
    {
        cin >> s;
        for (i = 0; i < s.size(); i++)
            if (s[i] == 'G') x = i;
               else if (s[i] == 'S') y = i;
        if (x < y) 
           l = y-x;
        else
        {
            flag = 1;
            break;
        }  
        if (a[l] == 0) {rez++;a[l]++;}
    }
    if (flag)
       cout << -1 << endl;
    else
        cout << rez << endl;
    return 0;
}