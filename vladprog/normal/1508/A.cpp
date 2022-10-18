#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

bool solve(const string&a,const string&b,char x,char y)
{
    vector<int> p{0};
    for(char c:a)
        if(c==x)
            p.push_back(0);
        else
            p.back()++;
    vector<int> q{0};
    for(char c:b)
        if(c==x)
            q.push_back(0);
        else
            q.back()++;
    while(p.size()<q.size())
        p.push_back(0);
    while(q.size()<p.size())
        q.push_back(0);
    int len=p.size();
    string s;
    for(int i=0;i<len;i++)
        s+=string(max(p[i],q[i]),y)+x;
    s.pop_back();
    if(s.size()<=a.size()/2*3)
    {
        cout<<s<<"\n";
        return true;
    }
    else
        return false;
}

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
        string a,b,c;
        cin>>a>>b>>c;
        solve(a,b,'0','1')||
        solve(a,c,'0','1')||
        solve(b,a,'0','1')||
        solve(b,c,'0','1')||
        solve(c,a,'0','1')||
        solve(c,b,'0','1')||
        solve(a,b,'1','0')||
        solve(a,c,'1','0')||
        solve(b,a,'1','0')||
        solve(b,c,'1','0')||
        solve(c,a,'1','0')||
        solve(c,b,'1','0');
    }
}