#include <bits/stdc++.h>
#define rand() (rand()|rand()<<15)
using namespace std;
int n,cnt=60;
int tryit(int x)
{
    --cnt;
    printf("> %d\n",x);
    fflush(stdout);
    int val;
    scanf("%d",&val);
    return val;
}
int gcd(int x,int y)
{
    if (x==0) return y;
    if (y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    srand(time(0));
    scanf("%d",&n);
    int lx=0,rx=1000000000;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (tryit(mid)) lx=mid+1; else rx=mid;
    }
    int res;
    if (tryit(lx)) res=lx+1; else res=lx;
    int d=0;
    for (int i=1;i<=cnt;i++)
    {
        int x=(int)(rand()%n);
        x=(x+n)%n+1;
        printf("? %d\n",x);
        fflush(stdout);
        int val;
        scanf("%d",&val);
        d=gcd(d,res-val);
    }
    printf("! %d %d\n",res-(n-1)*d,d);
    cout << res << endl;
    return 0;
}