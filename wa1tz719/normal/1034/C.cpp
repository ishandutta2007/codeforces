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
#define ok o23k
struct edge
{
    int y;
    edge * next;
};
edge * new_edge()
{
    static edge a[1000005];
    static int top=0;
    return &a[top++];
}
edge * li[1000005];
void insert_edge(int x,int y)
{
    edge * t=new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
}
long long sums[1000005];
int a[1000005];
int ok[1000005];
const int modo=1000000007;
void dfs1(int x)
{
    edge * t;
    sums[x]=a[x];
    for (t=li[x];t!=0;t=t->next)
    {
        dfs1(t->y);
        sums[x]+=sums[t->y];
    }
}
bool dfs(int x,long long k)
{
    if (sums[x]<k)
    {
        return 0;
    }
    if (sums[x]==k)
    {
        return 0;
    }
    edge * t;
    long long rest=sums[x]%k;
    if (rest==0) rest=k;
    rest-=a[x];
    for (t=li[x];t!=0;t=t->next)
    {
        if (rest<0) return 1;
        bool p=dfs(t->y,k);
        if (p) return 1;
        rest-=sums[t->y]%k;
    }
    if (rest<0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int gcd(int x,int y)
{
    if (y==0) return x;
    return gcd(y,x%y);
}
int ans[1000005];
map<long long,int> ma;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    long long sum=0;
    int max_a=0;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        max_a=max(max_a,a[i]);
        sum+=a[i];
    }
    int gcd_val=0;
    for (i=0;i<n;i++)
    {
        gcd_val=gcd(gcd_val,a[i]);
    }
    for (i=0;i<n;i++)
    {
        a[i]/=gcd_val;
    }
    sum/=gcd_val;
    max_a/=gcd_val;
    for (i=1;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        x--;
        insert_edge(x,i);
    }
    int final_ans=1;
    dfs1(0);
    int cnt=0;
    ans[1]=1;
    ok[cnt++]=1;
    sort(sums,sums+n);
    for (i=0;i<n;i++)
    {
        ma[sums[i]]++;
    }
    for (i=2;i<=n;i++)
    {
        if (sum%i==0)
        {
            if ((sums[n-1]%i!=0)&&(sums[n-1]>i))
            {
                continue;
            }
            if (sum/i<max_a)
            {
                break;
            }
            int cnts=0;
            long long p=sum/i;
            long long pp;
            for (pp=p;pp<=sum;pp+=p)
            {
                cnts+=ma[pp]; 
                if (cnts<pp/p) break;
            }
            if (cnts==i)
            {
                int j;
                for (j=0;j<cnt;j++)
                {
                    if (i%ok[j]==0)
                    {
                        ans[i]+=ans[ok[j]];
                        ans[i]%=modo;
                    }
                }
                ok[cnt++]=i;
                final_ans=(final_ans+ans[i])%modo;
            }
        }
    }
    printf("%d\n",final_ans);
    return 0;
}