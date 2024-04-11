#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int a,b;
inline bool check(int x)
{
    int t=0,cnt=1;
    while(x)
    {
        if(x%10==4||x%10==7) t+=x%10*cnt,cnt*=10;
        x/=10;
    }
    return t!=b;
}
int main()
{
    scanf("%d%d",&a,&b);
    a++;
    while(check(a)) a++;
    printf("%d\n",a);
    return 0;
}