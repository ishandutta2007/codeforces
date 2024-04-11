#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e3+5;
int a[maxn];int b[maxn];bool used[maxn][2];
multiset<pair<int,int> > u;vector<int> ans;
int pl=0;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef LOCAL
    pl=1e9;
    #endif // LOCAL
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        int mia=*min_element(a,a+n);int mib=*min_element(b,b+n);
        vector<int> ch;
        if(mia<mib)
        {
            for(int i=0;i<n;++i)
            {
                ch.push_back(b[i]+mia);
                ch.push_back(b[i]-mia);
                ch.push_back(mia-b[i]);
            }
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                ch.push_back(a[i]+mib);
                ch.push_back(a[i]-mib);
                ch.push_back(mib-a[i]);
            }
        }
        vector<int> a1,b1;for(int i=0;i<n;++i) a1.push_back(a[i]); for(int i=0;i<n;++i) b1.push_back(b[i]);
        sort(a1.begin(),a1.end());sort(b1.begin(),b1.end());
        sort(ch.begin(),ch.end());ch.erase(unique(ch.begin(),ch.end()),ch.end());
        bool ok1=false;
        for(int d:ch)
        {
            if(d<0) continue;
            int p1=0;int p2=d;
            u.clear();
            for(int i=0;i<n;++i) u.insert({a[i],0}); for(int i=0;i<n;++i) u.insert({b[i],1});
            bool ok=true;ans.clear();
            while(!u.empty())
            {
                set<pair<int,int> >::iterator it=u.end();--it;
                pair<int,int> o=(*it);u.erase(it);
                if(d>=o.first)
                {
                    set<pair<int,int> >::iterator it=u.find({d-o.first,o.second^1});
                    if(it==u.end()) {ok=false;break;}
                    if(o.second==0) ans.push_back(o.first); else ans.push_back(d-o.first);
                    u.erase(it);
                }
                else
                {
                    set<pair<int,int> >::iterator it=u.find({o.first-d,o.second^1});
                    if(it==u.end()) {ok=false;break;}
                    if(o.second==0) ans.push_back(o.first); else ans.push_back(d-o.first);
                    u.erase(it);
                }
            }
            if(!ok) continue;
            ok1=true;
            vector<int> a2,b2;
            for(auto h:ans) a2.push_back(abs(h-p1)); for(auto h:ans) b2.push_back(abs(h-p2));
            sort(a2.begin(),a2.end());sort(b2.begin(),b2.end());
            assert(a1==a2 && b1==b2);
            cout<<"YES"<<endl;
            int pl3=pl;
            if(d>1e9) pl3=0;
            for(auto h:ans) {cout<<h+pl3<<' ';} cout<<endl;
            cout<<p1+pl3<<' '<<p2+pl3<<endl;
            break;
        }
        if(!ok1)
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}