#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d\n",&n);
    char a[n],b[n];
    scanf("%s\n%s",a,b);
    sort(a,a+n);
    sort(b,b+n);
    //printf("\nfor\n");
    for(int i=0,j=-1;i<n;i++)
    {
        do
        {
            j++;
            //printf("j++ : %d -> %d\nj<n : %d < %d\na[i]>b[j] : %d > %d\nResult: %d\n",j-1,j,j,n,a[i],a[j],(j<n&&a[i]>a[j])?1:0);
        }
        while(j<n&&a[i]>b[j]);
        if(i==n-1&&j<n)
        {
            printf("%d\n",0);
            break;
        }
        if(j==n)
        {
            printf("%d\n",n-i);
            break;
        }
    }
    //printf("\nfor\n");
    for(int i=0,j=-1;i<n;i++)
    {
        do
        {
            j++;
            //printf("j++ : %d -> %d\nj<n : %d < %d\na[i]>=b[j] : %d >= %d\nResult: %d\n",j-1,j,j,n,a[i],a[j],(j<n&&a[i]>=a[j])?1:0);
        }
        while(j<n&&a[i]>=b[j]);
        if(i==n-1&&j<n)
        {
            printf("%d\n",n);
            break;
        }
        if(j==n)
        {
            printf("%d\n",i);
            break;
        }
    }
}