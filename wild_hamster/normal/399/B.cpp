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
ll n,i,j,d,m,x,y,p,k,max1,a[100500],rez;
string s;
int main()
{
    cin >> n;
    cin >> s;
    /*rez = 0;
    ll flag = 1;
    while (1)
    {
          i = n-1;
          while (s[i] == 'R' && i >= 0)
                i--;
          if (i == -1)
             break;
          rez++;
          s[i] = 'R';
          for (j = i+1; j < n; j++)
              s[j] = 'B';
          cout << s << endl;
    }*/
    rez = 0;
    for (i = 0; i < n; i++)        
     if (s[i] == 'B')
        rez += (1LL<<i);
     cout << rez << endl;
    return 0;
}