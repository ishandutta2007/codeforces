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
typedef long long ll;
using namespace std;
string s;
ll rez,h,q,n,i,j,k1,k2,k3,d,x,k,y,xx,yy,m,l,r,c,t,sum,a[100500];

int main()
{
    cin >> h >> n;
    n--;
    l = 0;
    for (i = h-1; i >= 0; i--)
    {
        k = (n&(1LL<<i));
        if (k > 0) k = 1;
        if (k != l)
        rez += (1LL<<(i+1));
        else
        rez++;
        l = (k+1)%2;
    }
    cout << rez << endl;
    return 0;
}