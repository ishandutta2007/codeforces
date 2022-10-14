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
    cin >> n;
    cin >> s;
    ll rez = 0;
    for (i = 0; i < n-1; i++)
    {
        a[s[2*i]-'a'+'A']++;
        if (a[s[2*i+1]] > 0)
           a[s[2*i+1]]--;
        else
            rez++;
    }
    cout << rez << endl;
    return 0;
}