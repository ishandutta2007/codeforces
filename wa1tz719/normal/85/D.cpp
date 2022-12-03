#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<math.h>
#include<string>
#include<time.h>
#include<bitset>
#include<vector>
#include<memory>
#include<utility>
#include<stdio.h>
#include<sstream>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
vector<int> v;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    int i;
    int flag=0;
    long long ans;
    for (i=0;i<n;i++)
    {
        static char a[105];
        int x;
        scanf("%s",a);
        if (a[0]=='a')
        {
            scanf("%d",&x);
            v.insert(lower_bound(v.begin(),v.end(),x),x);
            flag=0;
        }
        if (a[0]=='d')
        {
            scanf("%d",&x);
            v.erase(lower_bound(v.begin(),v.end(),x));
            flag=0;
        }
        if (a[0]=='s')
        {
            if (flag==1)
            {
                cout<<ans<<'\n';
                continue;
            }
            ans=0;
            int i;
            for (i=2;i<v.size();i+=5)
            {
                ans+=v[i];
            }
            cout<<ans<<'\n';
            flag=1;
        }
    }
    return 0;
}