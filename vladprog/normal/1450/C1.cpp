#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=310;

string s[N];

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
            cin>>s[i];
        int cnt[3]={};
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(s[i][j]=='X')
                    cnt[(i+j)%3]++;
        pair best=min({pair(cnt[0],0),
                       pair(cnt[1],1),
                       pair(cnt[2],2)});
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(s[i][j]=='X'&&
                   (i+j)%3==best.y)
                    s[i][j]='O';
        for(int i=0;i<n;i++)
            cout<<s[i]<<"\n";
    }
}