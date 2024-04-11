#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
bool arr[2*maxn];
bool answ[maxn];
int fe[maxn];
void pl(int pos,int val) {while(pos<maxn) {fe[pos]+=val;pos|=(pos+1);}}
int get(int pos) {int ans=0;while(pos>=0) {ans+=fe[pos];pos&=(pos+1);--pos;} return ans;}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    mt19937 rnd;rnd.seed(1337);
    int n,q;cin>>n>>q;int a[n];int a1[n];
    for(int i=0;i<n;++i) {cin>>a[i];a1[i]=a[i];}
    vector<vector<int> > que;
    for(int cyc=0;cyc<q;++cyc)
    {
        int typ;cin>>typ;
        if(typ==1)
        {
            int pos,x;cin>>pos>>x;--pos;que.push_back({pos,x});
        }
        else
        {
            int l,r,k;cin>>l>>r>>k;--l;--r;
            que.push_back({l,r,k});
        }
    }
    vector<int> v;
    for(int i=0;i<n;++i) v.push_back(a[i]);
    for(int i=0;i<q;++i)
    {
        if(que[i].size()==2) v.push_back(que[i][1]);
        else answ[i]=true;
    }
    sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
    int b[n];int b1[n];for(int i=0;i<n;++i) {b[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();b1[i]=b[i];}
    int iter=0;
    while(++iter<1000 && clock()<2*CLOCKS_PER_SEC)
    {
        for(int i=0;i<v.size();++i) arr[i]=rnd()%2;
        for(int i=0;i<=n;++i) fe[i]=0;
        for(int i=0;i<n;++i) b[i]=b1[i];
        for(int i=0;i<n;++i)
        {
            pl(i,arr[b[i]]);
        }
        for(int i=0;i<q;++i)
        {
            vector<int> h=que[i];
            if(h.size()==2)
            {
                int pos=h[0];int val=h[1];
                pl(pos,-arr[b[pos]]);
                b[pos]=lower_bound(v.begin(),v.end(),val)-v.begin();
                pl(pos,arr[b[pos]]);
            }
            else
            {
                int l=h[0];int r=h[1];int k=h[2];
                int o=get(r)-get(l-1);
                if((o%k)!=0) {answ[i]=false;}
            }
        }
    }
    for(int i=0;i<q;++i)
    {
        if(que[i].size()==3)
        {
            cout<<(answ[i] ? "YES" : "NO")<<'\n';
        }
    }
    return 0;
}