#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int cnt[N][26];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n=s.size();
    s="_"+s;
    for(int i=1;i<=n;i++)
        for(int j=0;j<26;j++)
            cnt[i][j]=cnt[i-1][j]+(s[i]=='a'+j);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(l==r||s[l]!=s[r])
            cout<<"Yes\n";
        else
        {
            int cur=0;
            for(int j=0;j<26;j++)
                if(cnt[l-1][j]!=cnt[r][j])
                    cur++;
            cout<<(cur<=2?"No\n":"Yes\n");
        }
    }
}