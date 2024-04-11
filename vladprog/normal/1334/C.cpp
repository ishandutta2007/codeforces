#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

int a_[N],b_[N];
#define a(i) a_[((i)+n)%n]
#define b(i) b_[((i)+n)%n]

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a(i)>>b(i);
        int ans=0;
        for(int i=0;i<n;i++)
            if(a(i+1)>b(i))
                ans+=a(i+1)-b(i),
                a(i+1)=b(i);
        int mn=1e18;
        for(int i=0;i<n;i++)
            mn=min(mn,a(i));
        cout<<ans+mn<<"\n";
    }
}