#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

string s[N];
int pref[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i+1<n;i++)
        for(int j=0;j+1<m;j++)
            if(s[i+1][j]=='X'&&s[i][j+1]=='X')
                pref[j+1]++;
    for(int i=1;i<=m;i++)
        pref[i]+=pref[i-1];
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<(pref[r]-pref[l]?"NO\n":"YES\n");
    }
}