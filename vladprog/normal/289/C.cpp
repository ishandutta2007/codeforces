#include<bits/stdc++.h>

using namespace std;

const int inf=1e5;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n<k)return printf("-1"),0;
    if(n==1)return printf("a"),0;
    if(k==1)return printf("-1"),0;
    for(int i=1;i<=n-k+2;i++)
        printf((i%2)?"a":"b");
    for(int i=2;i<k;i++)
        printf("%c",'a'+i);
}