#include <iostream>
//#include <cmath>
/*#include <algorithm>
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
#define PI 3.14159265358979323846*/
#define MOD 1000000007
typedef long long ll;
using namespace std;
string s;
ll n,i,j,k1,k2,x,k,y,m,l,r,c,t,a[200005];

int main()
{
    cin >> n;
    if (n%2 == 1)
       cout << (n*n)/2+1 << endl;
    else
        cout << (n*n)/2 << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if ((i+j)%2 == 0)
               cout << 'C';
            else
                cout << '.';
        cout << endl;
    }
    return 0;
}