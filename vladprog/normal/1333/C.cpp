#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],pref[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        pref[i]=pref[i-1]+a[i];
    multiset<int> s{0};
    int ans=0;
    for(int i=1,j=0;i<=n;i++)
    {
        while(j+1<=n&&s.find(pref[j+1])==s.end())
            s.insert(pref[j+1]),
            j++;
        ans+=j-i+1;
//        cout<<i<<" : ";
//        for(int x:s)
//            cout<<x<<" ";
//        cout<<endl;
        s.erase(s.find(pref[i-1]));
    }
    cout<<ans;
}