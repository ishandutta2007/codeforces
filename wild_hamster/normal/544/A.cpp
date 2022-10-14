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
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll cur,k,oz,w,l,r,i,j,k1,k2,dr,n,m, t, qt, qh, md, a[5005], used[5005], x, y;
string s;
vector <string> dno;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> s;
    l = 0;
    for (i = 0; i < s.size();)
        if (!used[s[i]])
        {
            used[s[i]] = 1;
            dno.push_back("");
            while (used[s[i]] && i < s.size())
            {
                dno[l].push_back(s[i]);
                i++;
            }
            l++;
        }
    if (l < n)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (i = 0; i < n-1; i++)
        cout << dno[i] << "\n";
    for (i = n-1; i < l; i++)
        cout << dno[i];
    cout << endl;
    return 0;
}