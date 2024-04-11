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
ll x,y,l,r,i,j,n,k,d,m,tim[105],cnt[105],is_fixed[105],q,dr;
string s,t;
int main()
{
    //freopen("thimble.in","r",stdin);
    //freopen("thimble.out","w",stdout);
    cin >> s >> t;
    n = s.size();
    s[n-1] ++;
    for (i = n-1; i >= 0; i--)
        if (s[i] > 'z')
        {
         s[i-1]++;
         s[i] -= 26;
        }
    if (s!=t)
       cout << s << endl;
    else
        cout << "No such string" << endl;
    return 0;
}