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
ll n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,w,rez,a,b;

int main()
{
    cin >> a >> b;
    rez = 0;
    for (i = b; i <= b; i++)    
        rez = (((((((i+i*a+2LL)%tr)*a)%tr)*((tr+1)/2))%tr)*(ll)((((i-1LL)*i)/2LL)%tr))%tr;
    cout << rez << endl;
   return 0;
}