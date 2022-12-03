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
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct rules
{
    int a;
    int b;
    int c;
    void read()
    {
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        c--;
    }
};
int a[30005];
rules b[120005];
vector<int> v[30005];
int used[120005];
set<int> s;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        a[i]=4;
    }
    for (i=0;i<4*n;i++)
    {
        s.insert(i);
        b[i].read();
        v[b[i].a].push_back(i);
        v[b[i].b].push_back(i);
        v[b[i].c].push_back(i);
    }
    puts("YES");
    for (;!s.empty();)
    {
        set<int>::iterator ii=s.begin();
        printf("%d ",(*ii)+1);
        a[b[(*ii)].a]--;
        a[b[(*ii)].b]++;
        a[b[(*ii)].c]++;
        used[(*ii)]=true;
        int x;
        x=b[(*ii)].a;
        for (i=0;i<12;i++)
        {
            if (used[v[x][i]]) continue;
            s.erase(v[x][i]);
            a[b[v[x][i]].a]--;
            a[b[v[x][i]].b]++;
            a[b[v[x][i]].c]++;
            if ((a[b[v[x][i]].b]<=9)&&(a[b[v[x][i]].c]<=9))
            {
                s.insert(v[x][i]);
            }
            a[b[v[x][i]].a]++;
            a[b[v[x][i]].b]--;
            a[b[v[x][i]].c]--;
        }
        x=b[(*ii)].b;
        for (i=0;i<12;i++)
        {
            if (used[v[x][i]]) continue;
            s.erase(v[x][i]);
            a[b[v[x][i]].a]--;
            a[b[v[x][i]].b]++;
            a[b[v[x][i]].c]++;
            if ((a[b[v[x][i]].b]<=9)&&(a[b[v[x][i]].c]<=9))
            {
                s.insert(v[x][i]);
            }
            a[b[v[x][i]].a]++;
            a[b[v[x][i]].b]--;
            a[b[v[x][i]].c]--;
        }
        x=b[(*ii)].c;
        for (i=0;i<12;i++)
        {
            if (used[v[x][i]]) continue;
            s.erase(v[x][i]);
            a[b[v[x][i]].a]--;
            a[b[v[x][i]].b]++;
            a[b[v[x][i]].c]++;
            if ((a[b[v[x][i]].b]<=9)&&(a[b[v[x][i]].c]<=9))
            {
                s.insert(v[x][i]);
            }
            a[b[v[x][i]].a]++;
            a[b[v[x][i]].b]--;
            a[b[v[x][i]].c]--;
        }
        s.erase(*ii);
    }
    return 0;
}