#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int main()
{
    int A,B,C; scanf("%d%d%d",&A,&B,&C);
    if(A==0)
    {
        if(B==0)
        {
            if(C==0) puts("-1");
            else puts("0");
        }
        else
        {
            db x=-C/(db)B;
            printf("%d\n%.10f\n",1,x);
        }
    }
    else
    {
        ll delta=1ll*B*B-4ll*A*C;
        if(delta<0) puts("0");
        else if(delta==0) printf("%d\n%.10f\n",1,-B/(2.0*A));
        else
        {
            db x1=(-B+sqrt(delta))/(2.0*A);
            db x2=(-B-sqrt(delta))/(2.0*A);
            if(x1>x2) swap(x1,x2);
            printf("%d\n",2);
            printf("%.10f\n%.10f\n",x1,x2);
        }
    }
    return 0;
}