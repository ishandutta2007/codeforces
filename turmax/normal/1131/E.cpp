#include <bits/stdc++.h>

using namespace std;
#define int long long
int getl(string s)
{
    int l=0;
    while(s[l]==s[0] && l<s.size()) ++l;
    return l;
}
int getr(string s)
{
    int r=s.size()-1;
    while(s[r]==s.back() && r>=0) --r;
    return s.size()-r-1;
}
pair<vector <int>,vector<int> > merg(vector <int> a,vector <int> a1,vector <int> b,vector <int> b1)
{
    assert(a.size()==6 && b.size()==6);
    vector <int> res(6);
    res[0]=min(b[0]*(a[0]+1)+a[0],(int) 2e9);
    res[1]=b[1];res[3]=b[3];
    res[2]=b[2];if(b[2]==b[0]) {if(a[1]==b[1]) {res[2]=(a[2]+1)*b[2]+a[2];}}
    res[4]=b[4];if(b[4]==b[0]) {if(a[3]==b[3]) {res[4]=(a[4]+1)*b[4]+a[4];}}
    vector <int> ans(26);
    res[5]=0;
    //cout<<a[2]<<' '<<(char) a[1]<<' '<<(char) b[1]<<' '<<b[2]<<' '<<a1[0]<<' '<<b1[0]<<endl;
    for(int i=0;i<26;++i)
    {
        char u='a'+i;
        ans[i]=b1[i];
        if(a1[i]) ans[i]=max(ans[i],1LL);
        //cout<<(char) b[1]<<' '<<(char) b[3]<<endl;
        if(u==b[1]) ans[i]=b[2];
        if(u==b[3]) ans[i]=max(ans[i],b[4]);
        if(u==b[1] && a1[i]>0) ans[i]=max(ans[i],b1[i]+1);
        if(u==b[3] && a1[i]>0) ans[i]=max(ans[i],b1[i]+1);
        if(u==b[1] && u==b[3] && a1[i]>0) ans[i]=max(ans[i],b[2]+b[4]+1);
        if(u==b[1] && b[2]==b[0]) ans[i]=max(ans[i],(a1[i]+1)*b[2]+a1[i]);
        //cout<<i<<" i "<<ans[i]<<" ans[i] "<<endl;
        res[5]=max(res[5],ans[i]);
    }
    for(auto &h:res) h=min(h,(int) 2e9);
    for(auto &h:ans) h=min(h,(int) 2e9);
    return {res,ans};
}
vector <int> go1(string s)
{
    vector <int> res;
    for(char u='a';u<='z';++u)
    {
        int cur=0;
        int ans1=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==u) ++cur;
            else cur=0;
            ans1=max(ans1,cur);
        }
        res.push_back(ans1);
    }
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;++i) cin>>s[i];
    vector <int> a[n];
    vector <int> b[n];
    for(int i=0;i<n;++i)
    {
        int ans=0;
        int cur=0;
        for(int j=0;j<s[i].size();++j)
        {
            if(j==0 || s[i][j]==s[i][j-1]) ++cur;
            else cur=1;
            ans=max(ans,cur);
        }
        a[i].push_back(s[i].size());
        a[i].push_back(s[i][0]);
        a[i].push_back(getl(s[i]));
        a[i].push_back(s[i].back());
        a[i].push_back(getr(s[i]));
        a[i].push_back(ans);
        b[i]=go1(s[i]);
    }
    vector <int> cur=a[0];vector <int> cur1=b[0];
    //for(auto h:b[0]) cout<<h<<' ';
    //cout<<endl;
    for(int i=1;i<n;++i) {pair<vector<int>,vector<int> > o=merg(cur,cur1,a[i],b[i]);cur=o.first;cur1=o.second;}
    cout<<cur[5];
    return 0;
}