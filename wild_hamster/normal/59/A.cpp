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
ll n,i,j,k1,k2,x,y,m,l,r,c,t,a[200005];
void upper()
{
     for (i = 0; i < s.size(); i++)
         if (s[i] >= 'a' && s[i] <= 'z')
            s[i] += 'A' - 'a';
}
void lower()
{
     for (i = 0; i < s.size(); i++)
         if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 'a' - 'A';
}
int main()
{
    cin >> s;
    for (i = 0; i < s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z') k1++;
           else k2++;
    if (k2 >= k1) lower();
       else upper();
    cout << s << endl;
    return 0;
}