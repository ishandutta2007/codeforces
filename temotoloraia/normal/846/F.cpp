#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const ll N=1000000;
ll n,a[N+5];
ll mas[N+5];
double ans;
int main()
{
    cin>>n;
    for (ll i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (ll i=1;i<=N;i++)
        mas[i]=n+1;
    for (ll i=n;i>0;i--){
        ans+=(mas[a[i]]-i)*i*2-1;
        mas[a[i]]=i;
    }
    double x=n*n;
    ans/=x;
    printf("%.6f",ans);
    return 0;
}