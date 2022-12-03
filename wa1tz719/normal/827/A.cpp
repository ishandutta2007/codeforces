#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
string a[1000005];
vector<pair<int,int> > v[2000005];
char c[2000005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    int i;
    for (i=0;i<n;i++)
    {
        cin>>a[i];
        int j;
        int k;
        cin>>k;
        for (j=0;j<k;j++)
        {
            int x;
            cin>>x;
            x--;
            v[x].push_back(make_pair(x+a[i].size(),i));
        }
    }
    priority_queue<pair<int,int> > q;
    for (i=0;i<=2000000;i++)
    {
        vector<pair<int,int> >::iterator ii;
        for (ii=v[i].begin();ii!=v[i].end();ii++)
        {
            q.push(*ii);
        }
        for (;!q.empty();)
        {
            if (q.top().first<=i) q.pop(); else break;
        }
        if (q.empty())
        {
            c[i]=' ';
        }
        else
        {
            int t1=q.top().second;
            int t2=q.top().first;
            c[i]=a[t1][i-t2+a[t1].size()];
        }
    }
    for (i=2000000;i>=0;i--)
    {
        if (c[i]!=' ') break;
    }
    int j;
    for (j=0;j<=i;j++)
    {
        if (c[j]!=' ') printf("%c",c[j]); else printf("a");
    }
    return 0;
}