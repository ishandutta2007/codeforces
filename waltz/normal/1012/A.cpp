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
int a[1000005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<2*n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n+n);
    long long ans=(long long)(a[n-1]-a[0])*(a[n+n-1]-a[n]);
    for (i=0;i<=n;i++)
    {
        ans=min(ans,(long long)(a[n+n-1]-a[0])*(a[i+n-1]-a[i]));
    }
    cout<<ans<<endl;
    return 0;
}