#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
const int maxn=2e6+10;
const double PI=acos(0)*2;

void solve()
{
    int n;scanf("%d",&n);
    string s;cin>>s;
    int l=0,r=s.length()-1;
    while(s[l]=='0')l++;
    while(s[r]=='1')r--;
    if(l>r)cout<<s<<endl;
    else
    {
        cout<<s.substr(0,l);
        cout<<s.substr(r,s.length()-r)<<endl;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    ios::sync_with_stdio(false);cin.tie(0);
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
}