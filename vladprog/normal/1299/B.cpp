#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int x[N],y[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    if(n%2)
        cout<<"NO",exit(0);
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i],
        x[i]*=2,y[i]*=2;
    int x0=(x[1]+x[n/2+1])/2;
    int y0=(y[1]+y[n/2+1])/2;
    for(int i=2;i<=n/2;i++)
        if((x[i]+x[n/2+i])/2!=x0||
           (y[i]+y[n/2+i])/2!=y0)
            cout<<"NO",exit(0);
    cout<<"YES";
}