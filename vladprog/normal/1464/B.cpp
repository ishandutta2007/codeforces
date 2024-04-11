#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

//vector<tuple<int,int,string>> ans;
//
//void solve(string s)
//{
//    int pos=-1;
//    for(int i=0;i<s.size();i++)
//        if(s[i]=='?')
//        {
//            pos=i;
//            break;
//        }
//    if(pos!=-1)
//    {
//        s[pos]='0';
//        solve(s);
//        s[pos]='1';
//        solve(s);
//        return;
//    }
//    int x=0,y=0;
//    for(int i=0;i<s.size();i++)
//        for(int j=i+1;j<s.size();j++)
//            if(s[i]=='0'&&s[j]=='1')
//                x++;
//            else if(s[i]=='1'&&s[j]=='0')
//                y++;
//    ans.push_back({x,y,s});
//}

int ans=1e18;
string s;
int x,y;

void solve()
{
    int l0=0,l1=0,r0=0,r1=0;
    int res=0;
    for(char c:s)
        if(c=='0')
            res+=r1*y,
            r0++;
        else
            res+=r0*x,
            r1++;
    ans=min(ans,res);
    for(char c:s)
        if(c=='0')
            r0--,l0++;
        else if(c=='1')
            r1--,l1++;
        else
        {
            r1--;
            res-=l0*x;
            res-=r0*y;
            res+=l1*y;
            res+=r1*x;
            ans=min(ans,res);
            l0++;
        }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    string s;
//    cin>>s;
//    solve(s);
//    sort(ans.begin(),ans.end());
//    for(auto[x,y,s]:ans)
//        cout<<s<<" \t "<<x<<" \t "<<y<<"\n";

    cin>>s>>x>>y;
    solve();
    for(char&c:s)
        if(c=='0')
            c='1';
        else if(c=='1')
            c='0';
    swap(x,y);
    solve();
    cout<<ans;
}