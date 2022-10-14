 #include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll sum,x1,x2,a1,b1,k,j,x,m,rez1,rez2,cnt,d,i,n,a[100500];

int main()
{
    cin >> n;
    if (n < 4)
       cout << "NO" << endl;
     else if (n%2 == 0)
     {
      cout << "YES" << endl;
      cout << "1 * 2 = 2" << endl;
      cout << "2 * 3 = 6" << endl;
      cout << "6 * 4 = 24" << endl;
      for (i = 5; i < n; i+= 2)
      {
          cout << i+1 << " - " << i << " = " << 1 << endl;
          cout << "24 * 1 = 24" << endl;
      }
     }
     else
     {
        cout << "YES" << endl;
      cout << "5 * 4 = 20" << endl;
      cout << "20 + 3 = 23" << endl;
      cout << "23 + 2 = 25" << endl;
      cout << "25 - 1 = 24" << endl;
      for (i = 6; i < n; i+= 2)
      {
          cout << i+1 << " - " << i << " = " << 1 << endl;
          cout << "24 * 1 = 24" << endl;
      } 
     }
    return 0;
}