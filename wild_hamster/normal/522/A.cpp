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
#define MOD 1000000009
typedef long long ll;
using namespace std;
map <string, ll> used;
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,max1,a[105000],b[105000];
string s,s1,s2,s3;
map <string, vector<string> > f;
string toc(string x)

{
       for (int i = 0; i < x.size(); i++)
           if (x[i] >= 'A' && x[i] <= 'Z')
              x[i] = x[i] + 'a' - 'A';
       return x;
}
void dfs(string v, ll lev)
{
       max1 = max(max1,lev);
       for (int i = 0; i < f[v].size(); i++)
           dfs(f[v][i],lev+1);
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s1 >> s2 >> s3;
        s1 = toc(s1);
        s3 = toc(s3);
        f[s3].push_back(s1);
    }
    max1 = 1;
    dfs("polycarp",1);
    cout << max1 << endl;
    return 0;
}