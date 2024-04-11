#include <iostream>
#include <stdlib.h>

using namespace std;

struct order
    {
        long int st,p,m;
    };
    order a[1000];
    struct table
    {
        long int st,cap,book;
    };
    table b[1000];
int comparea(const void* x,const void* y)
{
    return ((order*)y)->m-((order*)x)->m;
}
int compareb(const void* x,const void* y)
{
    return ((table*)x)->cap-((table*)y)->cap;
}
int main()
{
    long int n,i,j,m,re_ac;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i].p>>a[i].m;
        a[i].st=i+1;
    }
    cin>>m;
    for(i=0;i<m;i++){cin>>b[i].cap; b[i].st=i+1; b[i].book=0;}
    qsort(a,n,sizeof(order),comparea);
    qsort(b,m,sizeof(table),compareb);
    long int maxcash=0;re_ac=0;
    for(i=0;i<n;i++)
    {
         for(j=0;j<m;j++) if ((b[j].cap>=a[i].p)&&(b[j].book==0))
         {
             b[j].book=a[i].st;
             maxcash+=a[i].m;
             re_ac++;
             break;
         }
    }
    cout<<re_ac<<" "<<maxcash<<endl;
    for(i=0;i<m;i++) if (b[i].book!=0) cout<<b[i].book<<" "<<b[i].st<<endl;
}