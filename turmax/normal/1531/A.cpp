#include <bits/stdc++.h>

using namespace std;
#define int long long
set <int> locked;
set <int> ua;
const int maxn=1e5+5;
string s[maxn];
int n;
void ch(int i)
{
    if(locked.count(i)) locked.erase(i);
    if(ua.count(i)) ua.erase(i);
    if(s[i]=="lock" || s[i]=="unlock") {locked.insert(i);}
    if(s[i]=="unlock" && i!=(n+1) && s[i+1]!="lock" && s[i+1]!="unlock") {ua.insert(i);}
}
string getans()
{
    if(ua.empty())
    {
        return "blue";
    }
    set <int>::iterator it=ua.end();
    it--;
    int x=(*it);
    int o=(*locked.upper_bound(x));
    //cout<<o<<" o "<<endl;
    return s[o-1];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    s[0]="unlock";
    s[n+1]="lock";
    for(int i=1;i<=n;++i) cin>>s[i];
    for(int i=0;i<=(n+1);++i)
    {
         if(s[i]=="lock" || s[i]=="unlock") {locked.insert(i);}
         if(s[i]=="unlock" && i!=(n+1) && s[i+1]!="lock" && s[i+1]!="unlock") {ua.insert(i);}
    }
    cout<<getans()<<'\n';
    int t;
    t=0;
    while(t--)
    {
        int i;string z;
        cin>>i>>z;
        s[i]=z;
        ch(i);ch(i-1);
        //for(auto h:ua) cout<<h<<' ';
        //cout<<endl;
        cout<<getans()<<'\n';
    }
    return 0;
}