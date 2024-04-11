#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        string t;
        for(int i=1;i<=k-1;i++)
            t+="()";
        for(int i=1;i<=(n-2*(k-1))/2;i++)
            t+="(";
        for(int i=1;i<=(n-2*(k-1))/2;i++)
            t+=")";
        cout<<n<<"\n";
        for(int i=0;i<n;i++)
        {
            int j=i;
            while(s[j]!=t[i])
                j++;
            cout<<i+1<<" "<<j+1<<"\n";
            reverse(s.begin()+i,s.begin()+j+1);
        }
    }
}