#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;int a[n+1];int b[n+1];a[n]=(-1);b[n]=(-1);for(int i=0;i<n;++i) {cin>>a[i];b[i]=a[i];} for(int i=1;i<n;++i) a[i]=min(a[i],a[i-1]);
        set <pair<int,int> > d;d.insert({-0,a[0]});for(int i=1;i<=n;++i) if(a[i]!=a[i-1]) d.insert({-i,a[i]});
        for(int cyc=0;cyc<m;++cyc)
        {
            int pos,val;cin>>pos>>val;--pos;
            if(val==0) {cout<<d.size()-1<<' ';continue;}
            pair<int,int> o=(*d.lower_bound(make_pair(-pos,(int) -1)));
            int pos1=-o.first;int val1=o.second;b[pos]-=val;int val2=b[pos];
            if(pos1==pos)
            {
                d.erase(o);
            }
            if(val2<o.second) {
            d.insert({-pos,val2});
            while(true)
            {
            set <pair<int,int> >::iterator it=d.find({-pos,val2});
            --it;
            if((*it).second>=val2)
            {
                d.erase(it);
            }
            else {break;}
            }
            }
            cout<<d.size()-1<<' ';
        }
        cout<<'\n';
        /*for(auto h:d)
        {
            cout<<h.first<<' '<<h.second<<'\n';
        }*/
    }
    return 0;
}