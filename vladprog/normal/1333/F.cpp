#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e5+100;

int f[N];
bool b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        b[i]=true;
    f[n+1]=1e9;
    f[n]=n;
    int cur=n;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=2*(i+1);j<=n;j+=i+1)
            cur-=b[j],
            b[j]=false;
        f[i]=cur;
    }
    cur=0;
    for(int i=2;i<=n;i++)
    {
        while(f[cur]<i)
            cur++;
        cout<<cur<<" ";
    }
}