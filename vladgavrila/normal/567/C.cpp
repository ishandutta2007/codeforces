#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

#define maxn 300010

int n, k;
int v[maxn];
map<int, long long> mp0, mp1;
long long sol;

int main()
{
    cout.sync_with_stdio(false);

    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        if(v[i]%k==0)
        {
            sol = sol + mp1[v[i]/k];
            mp1[v[i]] = mp1[v[i]] + mp0[v[i] / k];
        }
        mp0[v[i]] = mp0[v[i]] + 1;
    }

    cout<<sol<<"\n";

    return 0;
}