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
ll x,y,w,l,r,i,j,n,t,k,k1,k2,d,m,q,dr,a[100005],b[100005],c[100050];
string s;
int main()
{
    cin >> s;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        x--;
        a[x]++;
    }
    for (i = 0; i < s.size()/2; i++)
    {
        l += a[i];
        if (l%2 != 0)
           swap(s[i],s[s.size()-i-1]);
    }
    cout << s << endl;
    return 0;
}