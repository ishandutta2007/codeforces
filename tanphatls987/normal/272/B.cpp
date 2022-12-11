#include <iostream>
#include <stdlib.h>
using namespace std;

int compare(const void*x,const void*y)
{
    return *(int*)x-*(int*)y;
}
int main()
{
    long long n,i,tmp,j,c;
    int a[100001]={0},h[100000]={0};
    int64_t ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        while(tmp) {a[i]+=tmp%2;tmp/=2;}
    }
    /*qsort(a,n,sizeof(int),compare);*/
    i=0;ans=0;
    /*while (i<n-1)
    {
        j=i;
        while((i<n-1)&&(a[i]==a[i+1])) i++;
        ans+=((i-j+1)*(i-j))/2;
        i++;
    }*/
    for(i=0;i<n;i++)if (!h[i])
    {
        c=1;h[i]=1;
        for(j=i+1;j<n;j++) if (a[j]==a[i]) {c++;h[j]=1;}
        ans+=(c*(c-1))/2;
    }
    cout<<ans;
}