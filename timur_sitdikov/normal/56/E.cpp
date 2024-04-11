#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF 1000000000

const int maxn=100005;
struct triplet
{int x, h, ind;};
triplet trpl[maxn];
int ans[maxn], ans1[maxn];

bool cmp(triplet & a, triplet &b)
{return a.x<b.x;}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, p, q, j;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> trpl[i].x >> trpl[i].h;
        trpl[i].ind=i;
    }
    sort(trpl, trpl+n, cmp);
    trpl[n].x=INF;
    for(i=n-1; i>=0; i--)
    {
        for(j=i+1; trpl[j].x<trpl[i].x+trpl[i].h; j+=ans1[j]);
        ans1[i]=j-i;
        
    }
    for(i=0; i<n; i++)
        ans[trpl[i].ind]=ans1[i];
    for(i=0; i<n; i++)
        cout << ans[i] << " ";
}