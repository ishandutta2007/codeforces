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
ll n,i,j,k,k1,k2,d,x,y,m,len,r,sum,start,in[100500],out[100500],power[100500];
vector <ll> graph[100500];
string s,rez;
void dfs(int v)
{
     while (power[v] < graph[v].size())
     {
           dfs(graph[v][power[v]++]);
     }
     rez.push_back(v%256);
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        ll v = s[0]*256+s[1];
        ll to = s[1]*256+s[2];
        graph[v].push_back(to);
        in[v]++;
        out[to]++;
        start = v;
    }
    for (i = 0; i < 65536; i++)
    {
        if (in[i] == out[i]+1 && k1 == 0) 
        {
         k1++;
         start = i;
        } else
        if (in[i]+1 == out[i] && k2 == 0) 
        {
         k2++;
        } else
        if (in[i] != out[i])
        {
           cout << "NO" << endl;
           return 0;
        }
    }
    dfs(start);    
    rez.push_back(start/256);
    reverse(rez.begin(),rez.end());
    if (rez.size() == n+2)
    {
       cout << "YES" << endl;
         cout << rez << endl;
    } else
    cout << "NO" << endl;
    return 0;
}