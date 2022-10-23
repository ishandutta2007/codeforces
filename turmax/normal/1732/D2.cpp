#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e5+5;
vector<int> d[maxn];
map<int,int> answ;
map<int,int> u;
map<int,set<int> > h;
struct qqq
{
    vector<int> fe;
    int get(int pos) {int ans=0;while(pos>=0) {ans+=fe[pos];pos&=(pos+1);--pos;} return ans;}
    void pl(int pos,int val) {while(pos<fe.size()) {fe[pos]+=val;pos|=(pos+1);}}
    void pl1(int x)
    {
        while(fe.size()<=x)
        {
            fe.push_back(0);int sz=fe.size()-1;for(auto h:d[sz]) {fe[sz]+=fe[h];}
        }
        pl(x,1);
    }
    void mi1(int x)
    {
        pl(x,-1);
    }
    int getans()
    {
        fe.push_back(0);int sz=fe.size()-1;for(auto h:d[sz]) {fe[sz]+=fe[h];}
        int low=0;int up=fe.size();
        while(up-low>1)
        {
            int mid=(low+up)/2;
            if(get(mid)==mid) low=mid;
            else up=mid;
        }
        return up;
    }
};
map<int,qqq> res;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) if((i|(i+1))<maxn) d[i | (i+1)].push_back(i);
    int t;cin>>t;
    while(t--)
    {
        char s;int k;cin>>s>>k;
        if(s=='+') {u[k]++;for(int x:h[k]) res[x].pl1(k/x);}
        else if(s=='-')
        {
            u[k]--;for(int x:h[k]) {res[x].mi1(k/x);}
        }
        else
        {
            if(!answ.count(k)) answ[k]=k;
            while(u[answ[k]])
            {
                h[answ[k]].insert(k);res[k].pl1(answ[k]/k);answ[k]+=k;
            }
            cout<<res[k].getans()*k<<'\n';
        }
    }
    return 0;
}