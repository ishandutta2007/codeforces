#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;

ll def1,def2,def3,def4,atk1,atk2,atk3,atk4,n,i,j,k,x,y,m,k1,k2;
string s;
int main()
{
    cin >> atk1 >> def1 >> atk2 >> def2;
    cin >> atk3 >> def3 >> atk4 >> def4;   
    if ((atk1 > def3 && atk1 > def4 && def2 > atk3 && def2 > atk4)||
    (atk2 > def3 && atk2 > def4 && def1 > atk3 && def1 > atk4))
          cout << "Team 1" << endl;
    else
    if (((atk3 > def1 && def4 > atk2)||(atk4 > def1 && def3 > atk2))&&
    ((atk3 > def2 && def4 > atk1)||(atk4 > def2 && def3 > atk1)))
          cout << "Team 2" << endl;
    else
        cout << "Draw" << endl;
    return 0;
}