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
int a[100005];
int b[100005];
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
        scanf("%d",&a[i]);
        b[i]=999999999;
    }
    int tot=0;
    for (i=0;i<n;i++)
    {
        int now=lower_bound(b,b+tot,a[i])-b;
        if (now==tot) tot++;
        b[now]=min(b[now],a[i]);
    }
    cout<<tot<<endl;
    return 0;
}