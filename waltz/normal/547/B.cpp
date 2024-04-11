#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int max_val[1<<20];
int left_val[1<<20];
int right_val[1<<20];
void change(int num,int l,int r,int loc)
{
    if (l==r-1)
    {
        max_val[num]=1;
        left_val[num]=1;
        right_val[num]=1;
        return;
    }
    int mid=(l+r)/2;
    if (loc<mid) change(num*2+1,l,mid,loc);
    else change(num*2+2,mid,r,loc);
    left_val[num]=left_val[num*2+1];
    if (left_val[num*2+1]==(mid-l))
    {
        left_val[num]+=left_val[num*2+2];
    }
    right_val[num]=right_val[num*2+2];
    if (right_val[num*2+2]==(r-mid))
    {
        right_val[num]+=right_val[num*2+1];
    }
    max_val[num]=max(max(max_val[num*2+1],max_val[num*2+2]),right_val[num*2+1]+left_val[num*2+2]);
}
int a[200005];
struct node
{
    int val;
    int id;
    friend bool operator < (const node &a,const node &b)
    {
        return a.val<b.val;
    }
};
node b[200005];
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
        b[i].val=a[i];
        b[i].id=i;
    }
    sort(b,b+n);
    int x=0;
    for (i=n-1;i>0;i--)
    {
        change(0,0,n,b[i].id);
        if (b[i-1].val!=b[i].val)
        {
            int t=max_val[0];
            for (;x<t;x++)
            {
                printf("%d ",b[i].val);
            }
        }
    }
    for (;x<n;x++)
    {
        printf("%d ",b[0].val);
    }
    printf("\n");
    return 0;
}