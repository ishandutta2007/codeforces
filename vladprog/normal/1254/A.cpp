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

const string abc="_qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
const int N=110;

string s[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int r,c,k;
        cin>>r>>c>>k;
        int sum=0;
        for(int i=0;i<r;i++)
            cin>>s[i],
            sum+=count(s[i].begin(),s[i].end(),'R');
        int cur=0;
        for(int i=0;i<r;i++)
            if(i%2==0)
                for(int j=0;j<c;j++)
                {
                    if(s[i][j]=='R'&&(cur+1)*k>sum)
                        k--,
                        sum-=cur,
                        cur=0;
                    if(s[i][j]=='R')
                        cur++;
                    s[i][j]=abc[k];
                }
            else
                for(int j=c-1;j>=0;j--)
                {
                    if(s[i][j]=='R'&&(cur+1)*k>sum)
                        k--,
                        sum-=cur,
                        cur=0;
                    if(s[i][j]=='R')
                        cur++;
                    s[i][j]=abc[k];
                }
        for(int i=0;i<r;i++)
            cout<<s[i]<<"\n";
    }
}