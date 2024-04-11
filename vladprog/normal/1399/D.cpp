#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N];

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
        string s;
        cin>>n>>s;
        s="_"+s;
        set<int> one,zero;
        int k=0;
        for(int i=1;i<=n;i++)
        {
            char c=s[i];
            set<int>& cur=(c=='1'?one:zero);
            set<int>& oth=(c=='0'?one:zero);
            if(oth.empty())
                k++,
                cur.insert(k),
                a[i]=k;
            else
                a[i]=*oth.begin(),
                cur.insert(*oth.begin()),
                oth.erase(oth.begin());
        }
        cout<<k<<"\n";
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}