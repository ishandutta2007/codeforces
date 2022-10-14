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
#define x1 flkdgl
#define x2 fdgdfgh
#define y1 lfdkgl
#define y2 lhkgflhkf
#define INF ((ll)1e+18)
typedef long long ll;
using namespace std;
ll v1,v2,z,w,l,r,i,j,n,x1,x2,y1,y2,x,y,d,m,q,sz,a[100500];
string s;
int main()
{
    cin >> y1 >> y2 >> x1 >> x2;
    if ((x1 >= y1 && x2 >= y2)||(max(x1,x2) >= y1+y2))
       cout << "Polycarp" << endl;
    else
        cout << "Vasiliy" << endl;
    return 0;
}