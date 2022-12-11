#include <stdio.h>
void qsort(int*,int,int);
int main()
{
    int a[100],i,n,check,w,pile;
    scanf("%i",&n);
    for (i=0;i<n;i++) scanf("%i",&a[i]);
    qsort(a,0,n-1);
    check=0;pile=0;
    do
    {
        w=0;pile++;
        for (i=0;i<n;i++) if(a[i]>=w){w++;check++;a[i]=-1;}
    }
    while (check<n);
    printf("%i",pile);
    return(0);
}
void qsort(int*d,int l,int r)
{
    int i,j,tmp,m;
    i=l;j=r;
    m=d[(l+r)/2];
    do
    {
        while (d[i]<m) i++;
        while (d[j]>m) j--;
        if (i<=j)
        {
            tmp=d[i];d[i]=d[j];d[j]=tmp;
            i++;j--;
        }
    }
    while (i<=j);
    if (i<r) qsort(d,i,r);
    if (l<j) qsort(d,l,j);
}