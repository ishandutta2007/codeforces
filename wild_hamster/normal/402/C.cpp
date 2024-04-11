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
typedef long long ll;
using namespace std;
ll n,m,j,p,l,r,t,x,y,k1,k2,k3,k4,k,i,a[100500],b[100500],w;
vector <string> rez;
int main()
{
    cin >> t;
    for (x = 0; x < t; x++)
    {
        cin >> n >> m;
        i = 1;
        k = 1;
        for (j = 0; j < 2*n + m; j++)
        {
            cout << i << " " << (i+k-1)%n + 1 << endl;
            i++;
            if (i%n == 1) k++, i = 1;            
        }
    }
   return 0;
}