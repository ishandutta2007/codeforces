#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

typedef long double ld;
const ld one=1;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

ld mn[N],mx[N],a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>mx[i];
    for(int i=1;i<=n;i++)
        cin>>mn[i];
    ld la=0,lb=0;
    for(int i=1;i<=n;i++)
    {
        ld A=1,
           B=la-lb-mx[i]-mn[i],
           C=-la*(mx[i]+mn[i])+mx[i],
           D=max<ld>(0,B*B-4*A*C);
        a[i]=(-B+sqrt(D))/(2*A);
        b[i]=mx[i]+mn[i]-a[i];
//        b[i]=(-B-sqrt(D))/(2*A);
//        cout<<i<<" ( "<<mx[i]<<" "<<mn[i]<<" ) -> "<<la<<" "<<lb<<" -> "<<A<<" "<<B<<" "<<C<<" "<<D<<" -> "<<a[i]<<" "<<b[i]<<"\n";
        la+=a[i];
        lb+=b[i];
    }
    cout<<fixed<<setprecision(10);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";
}