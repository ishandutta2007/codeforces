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
const int N=45000;
ll n,k,m;
ll a[N];
ll S;
ll ans,pas;
ll mas[N];
int main()
{
    cin>>n>>k>>m;
    for (int i=1;i<=k;i++){
        cin>>a[i];
        S+=a[i];
    }
    sort(a+1,a+k+1);
    for (ll i=0;i<=n && S*i<=m;i++){
        ll p=m-S*i;
        pas=(k+1)*i;
        int np=0;
        for (int l=1;l<=k;l++)
            for (int j=i+1;j<=n;j++)
                mas[++np]=a[l];
        //sort(mas+1,mas+np+1);
        for (int j=1;j<=np && p>=mas[j];j++){
            pas++;
            p-=mas[j];
        }
        if (pas>ans)
            ans=pas;
    }
    cout<<ans<<endl;
    return 0;
}