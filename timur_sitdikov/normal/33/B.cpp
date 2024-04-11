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
using namespace std;
#define pb push_back

string s1, s2;
long long g[200][200];
const long long inf=1000000000;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, i, j, k, c, ans, cur, curs;
    string a, b;
    cin >> s1 >> s2;
    if (s1.length()!=s2.length())
    {
        printf("-1");
        return 0;
    }
    cin >> n;
    for(i='a'; i<='z'; i++)
        for(j=i+1; j<='z'; j++)
            g[i][j]=g[j][i]=inf;
    for(i=0; i<n; i++)
    {
        cin >> a >> b >> c;
        g[a[0]][b[0]]=min(g[a[0]][b[0]], c);
    }
    for(k='a'; k<='z'; k++)
        for(i='a'; i<='z'; i++)
            for(j='a'; j<='z'; j++)
                g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
    ans=0;
    for(i=0; i<s1.length(); i++)
    {
        cur=2*inf;
        curs=0;
        for(j='a'; j<='z'; j++)
            if (g[s1[i]][j]+g[s2[i]][j]<cur)
            {
                cur=g[s1[i]][j]+g[s2[i]][j];
                curs=j;
            }
        if (cur>=inf)
        {
            printf("-1");
            return 0;
        }
        ans+=cur;
        s1[i]=curs;
    }
    cout << ans << endl << s1;

}