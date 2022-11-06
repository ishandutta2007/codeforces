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
#define point complex<double>
#define xx first
#define yy second

const int maxn=200005, al_sz=26, inf=1000000000;
string s, pattern;
int val[maxn][al_sz];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int i, j, n, m;
    long long ans;
    cin >> m >> n >> pattern;
    for(i=0; i<maxn; i++)
        for(j=0; j<al_sz; j++)
            val[i][j]=inf;
    for(i=0; i<n; i++)
        pattern[i]-='a';
    val[0][pattern[0]]=0;
    val[n-1][pattern[n-1]]=0;
    for(i=1; i<n; i++)
    {
        for(j=0; j<al_sz; j++)
            val[i][j]=min(val[i][j], val[i-1][j]+1);
        val[i][pattern[i]]=0;
    }
    for(i=n-2; i>=0; i--)
    {
        for(j=0; j<al_sz; j++)
            val[i][j]=min(val[i][j], val[i+1][j]+1);
        val[i][pattern[i]]=0;
    }
    for(i=n; i<maxn; i++)
        for(j=0; j<al_sz; j++)
            val[i][j]=min(val[i][j], val[i-1][j]+1);
    for(j=0; j<m; j++)
    {
        cin >> s;
        ans=0;
        for(i=0; i<(int)s.size(); i++)
            s[i]-='a';
        for(i=0; i<(int)s.size(); i++)
            if (val[i][s[i]]>=inf)
                ans+=(long long)s.size();
            else ans+=val[i][s[i]];
        cout << ans << endl;
    }
    
}