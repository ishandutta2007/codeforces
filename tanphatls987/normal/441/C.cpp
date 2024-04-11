#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("\n%d\n",k)
using namespace std;

const int maxi=100000;

int n,m,i,j,k,c=0;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
        if (i%2) {for(j=1;j<=m;j++)
    {
        c++;
        if ((c%2)&&(k>1)) printf("2 ");
        if (k==1) {printf("%d ",n*m-((i-1)*m+j-1));k--;}
        printf("%d %d ",i,j);
        if ((c%2==0)&&(k>1)) {k--;printf("\n");}
    }}
    else for(j=m;j>0;j--)
    {
        c++;
        if ((c%2)&&(k>1)) printf("2 ");
        if (k==1) {printf("%d ",(n-i)*m+j);k--;}
        printf("%d %d ",i,j);
        if ((c%2==0)&&(k>1)) {k--;printf("\n");}
    }

    /*
    if (m==1)
    {
        for(i=1;i<k;i++) printf("%d %d %d %d %d\n",2,2*i-1,1,2*i,1);
        printf("%d ",n-2*(k-1));
        for(i=2*(k-1)+1;i<=n;i++) printf("%d %d ",i,1);
    }
    else{
    for(i=1;i<k;i++)
    {
        printf("%d ",m);
        for(j=1;j<=m;j++) printf("%d %d ",i,j);
        printf("\n");
    }
    printf("%d ",(n-k+1)*m);
    bit=0;
    for(i=k;i<=n;i++)
    {
        if (!bit) for(j=1;j<=m;j++) printf("%d %d ",i,j);
        else for(j=m;j>0;j--) printf("%d %d ",i,j);
        bit=(1-bit);
    }}*/
}