#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=4e5+5;
vector<int> di[maxn];
int cnt[maxn];
int fe[maxn];
void pl(int pos,int val) {while(pos<maxn) {fe[pos]+=val;pos|=(pos+1);}}
int get(int pos) {int ans=0;while(pos>=0) {ans+=fe[pos];pos&=(pos+1);--pos;} return ans;}
int f(int l,int r)
{
    return max(0LL,r/6-(2*l-1)/6)+max(0LL,r/15-((5*l-1)/2)/15);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<maxn;++i) for(int j=i;j<maxn;j+=i) {di[j].push_back(i);}
    for(int j=1;j<maxn;++j) {cnt[j]=di[j].size()-1;pl(j,cnt[j]*(cnt[j]-1)/2);}
    int t;cin>>t;vector<pair<int,int> > que,que1;map<pair<int,int>,int> res;
    while(t--)
    {
        int l,r;cin>>l>>r;
        que.push_back({l,r});}
        que1=que;
        sort(que.begin(),que.end());
        int curl=1;
        for(auto [l,r]:que)
        {
            while(curl<l) {for(int i=2*curl;i<maxn;i+=curl) {--cnt[i];pl(i,-cnt[i]);} ++curl;}
            res[{l,r}]=get(r)-get(l+1);
        }
    for(auto [l,r]:que1)
    {
        cout<<(r-l+1)*(r-l)*(r-l-1)/6-res[{l,r}]-f(l,r)<<'\n';
    }
    return 0;
}