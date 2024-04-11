#include <bits/stdc++.h>

using namespace std;
#define int long long
int que(vector<int> v)
{
    cout<<"? "<<v.size()<<' ';for(auto h:v) cout<<h<<' '; cout<<endl;
    string res;cin>>res;if(res=="NO") return 0; else return 1;
}
void go(vector<int> v)
{
    if(v.size()<=2)
    {
        cout<<"! "<<v[0]<<endl;
        string s;cin>>s;if(s==":)") {exit(0);}
        if(v.size()==1) assert(false);
        cout<<"! "<<v[1]<<endl;
        cin>>s;if(s==":)") {exit(0);}
        assert(false);
    }
    vector<int> v0,v1,v2;
    for(int i=0;i<v.size()/3;++i) v0.push_back(v[i]);
    for(int i=v.size()/3;i<(2*v.size())/3;++i) v1.push_back(v[i]);
    for(int i=(2*v.size())/3;i<v.size();++i) v2.push_back(v[i]);
    int ans=que(v0);
    if(ans==0) {ans=que(v0);if(ans==0) {vector<int> u;for(auto h:v1) u.push_back(h); for(auto h:v2) u.push_back(h); go(u);exit(0);}}
    int ans1=que(v1);
    if(ans && ans1)
    {
        vector<int> u;for(auto h:v0) u.push_back(h); for(auto h:v1) u.push_back(h); go(u);exit(0);
    }
    if(ans && !ans1)
    {
        vector<int> u;for(auto h:v0) u.push_back(h); for(auto h:v2) u.push_back(h); go(u);exit(0);
    }
    assert(false);
}
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int> a(n);iota(a.begin(),a.end(),1);
    go(a);
    return 0;
}