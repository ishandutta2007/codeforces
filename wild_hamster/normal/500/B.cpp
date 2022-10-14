#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;

ll n,i,j,x,y,a[100500],used[1000],m,k1,k2,rez;
vector <ll> graph[1000],lalka,our;
void dfs(ll v)
{
     if (used[v]) return;
     used[v] = 1;
     lalka.push_back(v);
     ll i;
     for (i = 0; i < graph[v].size(); i++)
         dfs(graph[v][i]);
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '1')
               graph[i].push_back(j);
        }
    for (i = 0; i < n; i++)
    {
        dfs(i);
        sort(lalka.begin(),lalka.end());
        for (j = 0; j < lalka.size(); j++)
            our.push_back(a[lalka[j]]);
        sort(our.begin(),our.end());
        for (j = 0; j < lalka.size(); j++)
        {
            a[lalka[j]] = our[j];
            //cout << lalka[j] << " " << our[j] << endl;
        }
        lalka.clear(); our.clear();
    }
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}