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

ll n,i,j,x,y,rez[100500],m,k1,k2;
ll lalka(ll n)
{
 switch (n)
 {
        case 0: return 2;
        case 1: return 7;
        case 2: return 2;
        case 3: return 3;
        case 4: return 3;
        case 5: return 4;
        case 6: return 2;
        case 7: return 5;
        case 8: return 1;
        case 9: return 2;
 }
}
int main()
{
    cin >> n;
    k1 = n%10;
    k2 = n/10;
    cout << lalka(k1)*lalka(k2) << endl;
    return 0;
}