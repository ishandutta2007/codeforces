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

const int maxv=10000005, maxn=100005, d=10000;
int v1[maxv], v2[maxv];
vector<int> del1[maxn], del2[maxn], tmp;
char is_pr[d+d];
vector<int> pr;

void erat()
{
    int i, j;
    for(i=2; i<d; i++)
        is_pr[i]=1;
    for(i=2; i<d; i++)
        if (is_pr[i])
            for(j=i*i; j<d; j+=i)
                is_pr[j]=0;
    for(i=2; i<d; i++)
        if (is_pr[i])
            pr.pb(i);
}

void fact(int v)
{
    int i;
    tmp.clear();
    for(i=0; pr[i]*pr[i]<=v; i++)
        while(!(v%pr[i]))
        {
            tmp.pb(pr[i]);
            v/=pr[i];
        }
    if (v>1)
        tmp.pb(v);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, i, j, a;
    cin >> n >> m;
    erat();
    for(i=0; i<n; i++)
    {
        cin >> a;
        fact(a);
        del1[i]=tmp;
    }
    for(i=0; i<m; i++)
    {
        cin >> a;
        fact(a);
        del2[i]=tmp;
    }
    for(i=0; i<n; i++)
        for(j=0; j<(int)del1[i].size(); j++)
            v1[del1[i][j]]++;
    for(i=0; i<m; i++)
        for(j=0; j<(int)del2[i].size(); j++)
            v2[del2[i][j]]++;
    for(i=1; i<maxv; i++)
    {
        a=min(v1[i], v2[i]);
        v1[i]-=a;
        v2[i]-=a;
    }
    for(i=0; i<n; i++)
        for(j=0; j<(int)del1[i].size(); j++)
            if (v1[del1[i][j]])
                v1[del1[i][j]]--;
            else del1[i][j]=1;
    for(i=0; i<m; i++)
        for(j=0; j<(int)del2[i].size(); j++)
            if (v2[del2[i][j]])
                v2[del2[i][j]]--;
            else del2[i][j]=1;
    printf("%d %d\n", n, m);
    for(i=0; i<n; i++)
    {
        a=1;
        for(j=0; j<(int)del1[i].size(); j++)
            a*=del1[i][j];
        printf("%d ", a);
    }
    putchar('\n');
    for(i=0; i<m; i++)
    {
        a=1;
        for(j=0; j<(int)del2[i].size(); j++)
            a*=del2[i][j];
        printf("%d ", a);
    }
}