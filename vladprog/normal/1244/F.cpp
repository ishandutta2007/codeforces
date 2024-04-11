#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

bool b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    bool inf=true;
    for(int i=0;i<n;i++)
        if(s[i]!=s[(i+1)%n]&&s[i]!=s[(i+n-1)%n])
            b[i]=true;
        else
            inf=false;
    if(inf)
    {
        if(k%2)
            for(char&c:s)
                if(c=='W')
                    c='B';
                else
                    c='W';
        cout<<s;
        exit(0);
    }
    vector<pair<int,int>> seg;
    for(int i=0;i<n;i++)
        if(b[i])
            if(seg.empty()||seg.back().y!=i-1)
                seg.push_back({i,i});
            else
                seg.back().y++;
    if(b[0]&&b[n-1])
        seg.front().x=seg.back().x,
        seg.pop_back();
    for(auto p:seg)
    {
        int l=p.x,r=p.y;
        bool sw=false;
        for(int i=1;i<=k;i++)
        {
            if((r+1)%n==l)
                break;
            if(l==r)
            {
                if(!sw)
                    if(s[l]=='W')
                        s[l]='B';
                    else
                        s[l]='W';
                sw=false;
                break;
            }
            if(!sw)
            {
                if(s[l]=='W')
                    s[l]='B';
                else
                    s[l]='W';
                if(s[r]=='W')
                    s[r]='B';
                else
                    s[r]='W';
            }
            l=(l+1)%n;
            r=(r+n-1)%n;
            sw=!sw;
        }
        if(sw)
            for(int i=l;i!=(r+1)%n;i=(i+1)%n)
                if(s[i]=='W')
                    s[i]='B';
                else
                    s[i]='W';
    }
    cout<<s;
}