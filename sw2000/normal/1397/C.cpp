#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;

ll arr[N];
int n;

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",arr+i);
    }
    puts("1 1");
    printf("%lld\n",-arr[1]);
    printf("1 %d\n0",n);
    for(int i=2;i<=n;i++)
    {
        printf(" %lld",-arr[i]*n);
        arr[i]*=1-n;
    }
    if(n==1)
    {
        puts("\n1 1");
        printf("0");
        return 0;
    }
    printf("\n2 %d\n",n);
    for(int i=2;i<=n;i++){
        printf("%lld ",-arr[i]);
    }
    return 0;
}