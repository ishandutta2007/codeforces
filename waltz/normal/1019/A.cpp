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
vector<int> v[3005];
multiset<int> s;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<n;i++)
    {
        int p,c;
        scanf("%d%d",&p,&c);
        p--;
        v[p].push_back(c);
    }
    for (i=0;i<m;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    long long min_cost=10000000000000000ll;
    for (i=1;i<=n;i++)
    {
        int j;
        int cnt0=v[0].size();
        long long costs=0;
        s.clear();
        for (j=1;j<m;j++)
        {
            int k;
            for (k=0;k<(int)v[j].size()-(i-1);k++)
            {
                cnt0++;
                costs+=v[j][k];
            }
            for (;k<(int)v[j].size();k++)
            {
                s.insert(v[j][k]);
            }
        }
        {
            for (;cnt0<i;)
            {
                int t=(*s.begin());
                s.erase(s.begin());
                cnt0++;
                costs+=t;
            }
        }
        min_cost=min(min_cost,costs);
    }
    cout<<min_cost<<endl;
    return 0;
}