#include<bits/stdc++.h>

//#define d(v) // printf("%i\n",v)

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    printf("\n");
    /*for(int k=1,p=2,i=2;k<=n;i+=k)
        if(sqrt(i)==(int)sqrt(i)&&((int)sqrt(i))%(k+1)==0)
            printf("%6i -> %6i : %6i -> %6i -> %6i : %6i\n",k,k+1,p,i,(int)sqrt(i),(i-p)/k),p=sqrt(i),k++;
    printf("\n");
    printf("%6i -> %6i : %6i -> %6i -> %6i : %6i\n",1,2,2,4,2,2);
    for(long long k=2,i=2;k<=n;i=i+2*k,k++)
        printf("%6lli -> %6lli : %6lli -> %6lli -> %6lli : %6lli\n",k,k+1,i,(i+2*k)*(i+2*k),i+2*k,((i+2*k)*(i+2*k)-i)/k);*/
    printf("2\n");
    for(long long k=2,i=2;k<=n;i=i+2*k,k++)
        printf("%lli\n",i/k*(i-1)+4*(i+k));
}