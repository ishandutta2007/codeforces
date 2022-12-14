#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 200010
ll a[N],S;int n=1;
int main()
{
    int _;scanf("%d",&_);
    while(_--)
    {
        int z,x,y;
        scanf("%d",&z);
        if(z==1)
        {
            scanf("%d%d",&x,&y);
            S+=(ll)x*y;
            a[x]+=y;
        }else
        if(z==2)
        {
            scanf("%d",&x);
            a[n]+=-x;
            a[n+1]=x;
            n++;
            S+=x;
        }else
        if(z==3)
        {
            S-=a[n];
            a[n-1]+=a[n];
            a[n]=0;
            n--;
        }
        printf("%.9lf\n",(double)S/n);
    }
    return 0;
}