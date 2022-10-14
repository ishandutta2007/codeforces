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
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef int ll;
using namespace std;
ll b[200500],a[205205],i,j,n,k,k1,k2,m,x,y,l,r,a1,a2,a3,a4,a5,a6;
string s1,s2;
bool eq(string s1, string s2)
{

    ll m = s1.size();
    if ((m&1) == 1)
    {
        if (s1 == s2)
           return true;
        return false;
    }
    srand(time(0));
    ll k = (rand()&1);
    if (k)
    {
    if (eq(s1.substr(0,m/2),s2.substr(0,m/2)))
    {
        if (eq(s2.substr(m/2,m/2),s1.substr(m/2,m/2)))
           return true;
        return false;
    } 
    if (eq(s1.substr(0,m/2),s2.substr(m/2,m/2)))
    {
        if (eq(s2.substr(0,m/2),s1.substr(m/2,m/2)))
           return true;
        return false;
    }
    } else
    {
    
    if (eq(s1.substr(0,m/2),s2.substr(m/2,m/2)))
    {
        if (eq(s2.substr(0,m/2),s1.substr(m/2,m/2)))
           return true;
        return false;
    }
    if (eq(s1.substr(0,m/2),s2.substr(0,m/2)))
    {
        if (eq(s2.substr(m/2,m/2),s1.substr(m/2,m/2)))
           return true;
        return false;
    } 
    }
    return false;
}
int main()
{
    cin >> s1 >> s2;
    if (eq(s1,s2))
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}