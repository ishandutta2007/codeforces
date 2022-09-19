#include <bits/stdc++.h>

using namespace std;
#define int long long
map<int,int> u;vector<int> ans;pair<int,int> res;int cur=0;
void f(int x,int id)
{
    ans.push_back(id);cur+=x;if(u.count(cur)) {res={u[cur],ans.size()};} u[cur]=ans.size();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    pair<int,int> a[n],b[n];for(int i=0;i<n;++i) {cin>>a[i].first;a[i].second=i;} for(int i=0;i<n;++i) {cin>>b[i].first;b[i].second=i;}
    sort(a,a+n);sort(b,b+n);
    int suma=0,sumb=0;for(auto [key,val]:a) {suma+=key;} for(auto [key,val]:b) sumb+=key;
    if(suma>=sumb)
    {
        u[0]=0;cur=0;
        int la=0;int lb=0;
        while(la+lb<2*n)
        {
            if(lb==n)
            {
                f(a[la].first,a[la].second+1);++la;
            }
            else if(la==n)
            {
                f(-b[lb].first,-b[lb].second-1);++lb;
            }
            else
            {
                if(cur>=b[lb].first)
                {
                    f(-b[lb].first,-b[lb].second-1);++lb;
                }
                else
                {
                    f(a[la].first,a[la].second+1);++la;
                }
            }
        }
    }
    else
    {
        u[0]=0;cur=0;
        int la=0;int lb=0;
        while(la+lb<2*n)
        {
            if(lb==n)
            {
                f(-a[la].first,a[la].second+1);++la;
            }
            else if(la==n)
            {
                f(b[lb].first,-b[lb].second-1);++lb;
            }
            else
            {
                if(cur>=a[la].first)
                {
                    f(-a[la].first,a[la].second+1);++la;
                }
                else
                {
                    f(b[lb].first,-b[lb].second-1);++lb;
                }
            }
        }
    }
    vector<int> ans1;for(int i=res.first;i<res.second;++i) ans1.push_back(ans[i]);
    vector<int> va,vb;for(int x:ans1) {if(x>0) va.push_back(x); else vb.push_back(x);}
    cout<<va.size()<<endl;for(auto h:va) cout<<h<<' '; cout<<endl;  cout<<vb.size()<<endl; for(auto h:vb) cout<<-h<<' ';
    return 0;
}