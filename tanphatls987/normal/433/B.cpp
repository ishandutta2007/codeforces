#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

const int maxi=100020;

int n,i,idx,m,l,r,type,tmp,h[maxi],p[maxi];
int64_t a[maxi+1],b[maxi+1],sum;
int ldgt(int x)
{
    return x&(1+~x);
}
int compar(const void*x,const void*y)
{
    return p[*(int*)x]-p[*(int*)y];
}
int update(int64_t* a,int idx,int val)
{
        while (idx<=n)
        {
            a[idx]+=val;
            idx+=ldgt(idx);
        }
}
int64_t find_val(int idx,int64_t* a)
{
    sum=0;
    while (idx)
    {
        sum+=a[idx];
        idx-=ldgt(idx);
    }
    return sum;
}
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        h[i]=i;
    }
    for(i=0;i<n;i++) update(a,i+1,p[i]);
    qsort(h,n,sizeof(int),compar);
    for(i=0;i<n;i++) update(b,i+1,p[h[i]]);
    scanf("%d",&m);
    while (m)
    {
        scanf("%d%d%d",&type,&l,&r);
        if (type==1) printf("%I64d\n",(find_val(r,a)-find_val(l-1,a)));else printf("%I64d\n",(find_val(r,b)-find_val(l-1,b)));
        m--;
    }
}