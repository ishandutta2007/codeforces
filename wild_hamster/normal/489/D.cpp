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
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
int n,l,r,j,k,m,y,x,v,a[3005][3005],b[3005][3005],gr[3005][3005],invgr[3005][3005],rez,h,i,cnt;
vector <ll> graph[3005],invgraph[3005];
int main()
{
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--; y--;
        gr[x][y] = 1;
        invgr[y][x] = 1;
        graph[x].push_back(y);
        invgraph[y].push_back(x);
    }
    for (i = 0; i < n; i++)
    {
        ll sz = graph[i].size();
        for (j = 0; j < sz; j++)
            for (k = j+1; k < sz; k++)
            {
                ll j1 = graph[i][j], k1 = graph[i][k];
                if (invgr[i][j1]&&invgr[i][k1])
                {
                 //cout << j1 << " " << k1 << " " << i << endl;
                   rez--;
                }
                a[j1][k1]++;
                a[k1][j1]++;
            }
            
        sz = invgraph[i].size();
        for (j = 0; j < sz; j++)
            for (k = j+1; k < sz; k++)
            {
                ll j1 = invgraph[i][j], k1 = invgraph[i][k];
                b[j1][k1]++;
                b[k1][j1]++;
            }
    }
   /* for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
            rez += a[i][j]*b[i][j];
    cout << rez << endl;
    return 0;
}