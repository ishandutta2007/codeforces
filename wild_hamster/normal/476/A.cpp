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
ll n,i,j,d,m,x,r,y,p,k,max1,e,l,rez;
string s1,s2,s;

int main()
{
    cin >> n >> m;
    rez = -1;
    for (i = (n-1)/2+1; i <= n; i++)
    {
        if (i%m == 0)
        {
        rez = i;
        break;
        }
    }
        
    cout << rez << endl;
    return 0;
}