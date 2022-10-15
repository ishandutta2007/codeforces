#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
double p;
int main()
{
    scanf("%d%lf",&n,&p);
    int x=(int)(p*10000),y=10000;
    for(int i=0;i<=n;i++)
    {
        double a,b,c,d,prob;
        ll xx=3LL*(n-i)*(n-i-1)*i+6LL*(n-i)*i*(i-1)+2LL*i*(i-1)*(i-2);
        ll yy=2LL*n*(n-1)*(n-2);
        //xx/yy>=x/y
        if(xx*y>=x*yy) {printf("%d\n",i); return 0;}
    }
    assert(0);
    return 0;
}