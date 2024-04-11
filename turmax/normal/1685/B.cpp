#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int a,b,c,d;cin>>a>>b>>c>>d;string s;cin>>s;
        int n=s.size();int cnt1=0,cnt2=0;
        for(int i=0;i<n;++i) {if(s[i]=='A') ++cnt1; else ++cnt2;}
        if(cnt1!=a+c+d) {cout<<("NO")<<'\n';continue;}
        int cur=0;vector<pair<int,char> > v;
        for(int i=0;i<n;++i)
        {
            if(i==(n-1)) {if(cur) {v.push_back({cur,s[i]});} continue;}
            if(s[i]!=s[i+1]) {++cur;}
            else if(cur) {v.push_back({cur,s[i]});cur=0;}
        }
        int sum=0;int c1=0;int c2=0;
        vector<int> c3,d3;int c0=0;int d0=0;
        for(auto h:v)
        {
            ++h.first;
            /*if(s=="ABAAB")
            {
                cout<<h.first<<' '<<h.second<<'\n';
            }*/
            if(h.first%2==1) {c1+=(h.first/2);c2+=(h.first/2);c0+=h.first/2;d0+=h.first/2;sum+=(h.first/2);}
            else if(h.second=='B') {c1+=(h.first/2);c2+=(h.first/2)-1;d3.push_back(h.first/2-1);c0+=h.first/2;sum+=(h.first/2);}
            else {c1+=(h.first/2)-1;c2+=(h.first/2);c3.push_back(h.first/2-1);d0+=h.first/2;sum+=(h.first/2);}
        }
        if(!(sum>=c+d && c1>=c && c2>=d)) {cout<<"NO"<<'\n';continue;}
        //cout<<c0<<' '<<d0<<'\n';
        int sum1=sum;
        sort(c3.begin(),c3.end());sort(d3.begin(),d3.end());
        while(c0<c && !c3.empty())
        {
            sum1--;c0+=c3.back();c3.pop_back();
        }
        while(d0<d && !d3.empty())
        {
            sum1--;d0+=d3.back();d3.pop_back();
        }
        if(!(sum1>=c+d && c0>=c && d0>=d)) {cout<<"NO"<<'\n';continue;}
        cout<<"YES"<<'\n';
    }
    return 0;
}