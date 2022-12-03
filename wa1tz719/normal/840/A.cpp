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
struct node
{
    int val;
    int id;
    friend bool operator < (const node &a,const node &b)
    {
        return a.val<b.val;
    }
};
int ans[200005];
int a[200005];
node b[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    int n;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++)
    {
        scanf("%d",&b[i].val);
        b[i].id=i;
    }
    sort(a,a+n);
    sort(b,b+n);
    for (i=0;i<n;i++)
    {
        ans[b[i].id]=a[n-i-1];
    }
    for (i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}