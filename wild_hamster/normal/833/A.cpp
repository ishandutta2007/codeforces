#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,w,path_w,m,a[100500];
ll gcd(ll a, ll b)
{
    return (b==0?a:gcd(b,a%b));
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d",&x,&y);
        ll g = gcd(x,y);
        ll x1 = x/g, y1 = y/g;
        if (y%(1LL*y1*y1*x1) != 0 || x%(1LL*x1*x1*y1) != 0)
        {
            printf("No\n");
            continue;
        }
        y /= (1LL*y1*y1*x1); x /= (1LL*x1*x1*y1);
        if (x != y)
        {
            printf("No\n");
            continue;
        }
        ll tmp = exp(1./3*log(x));
        tmp--;
        while (1LL*tmp*tmp*tmp < x)
            tmp++;
        if (tmp*tmp*tmp == x)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}