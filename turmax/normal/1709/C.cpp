#include <bits/stdc++.h>

using namespace std;
#define int long long
bool ok(string s)
{
    int n=s.size();
    int sh=0;for(int i=0;i<n;++i) {if(s[i]=='(') ++sh; else --sh; if(sh<0) return false;}
    assert(sh==0);return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        int n=s.size();vector<int> a;int cnt1=0,cnt2=0;for(int i=0;i<n;++i) {if(s[i]=='?') a.push_back(i); else if(s[i]=='(') ++cnt1; else ++cnt2;}
        int diff=cnt1-cnt2;for(int i=0;i<(a.size()-diff)/2;++i) s[a[i]]='('; for(int i=(a.size()-diff)/2;i<a.size();++i) s[a[i]]=')';
        assert(ok(s));
        if(a.empty()) {cout<<"YES"<<'\n';continue;}
        if(s[a[0]]==')') {cout<<"YES"<<'\n';continue;}
        if(s[a[a.size()-1]]=='(') {cout<<"YES"<<'\n';continue;}
        swap(s[a[(a.size()-diff)/2-1]],s[a[(a.size()-diff)/2]]);
        if(ok(s)) {cout<<"NO"<<'\n';}
        else {cout<<"YES"<<'\n';}
    }
    return 0;
}