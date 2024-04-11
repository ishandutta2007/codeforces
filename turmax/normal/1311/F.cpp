#include <bits/stdc++.h>

using namespace std;
#define int long long
bool comp(pair <int,int> u1,pair <int,int> u2)
{
    return (make_pair(u1.second,u1.first)<make_pair(u2.second,u2.first));
}
int go(vector <int> t){
    if(t.size()<=1)
    {
        return 0;
    }
    int n=t.size();
    vector <int> v1;
    vector <int> v2;
    for(int i=0;i<(n/2);++i)
    {
        v1.push_back(t[i]);
    }
    for(int i=(n/2);i<n;++i)
    {
        v2.push_back(t[i]);
    }
    int ans=go(v1)+go(v2);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int t1=v1.size();
    int t2=v2.size();
    vector <int> pr2(t2+1);
    pr2[0]=0;
    for(int i=0;i<t2;++i)
    {
        pr2[i+1]=pr2[i]+v2[i];
    }
    //cout<<ans<<" ans "<<endl;
    for(int i=0;i<t1;++i)
    {
        int x=v1[i];
        //cout<<x<<" x "<<endl;
        int y=lower_bound(v2.begin(),v2.end(),x)-v2.begin();
        ans+=(pr2[t2]-pr2[y]-(t2-y)*x);
    }
    return ans;
}
int go2(vector <int> v)
{
    int s=0;
    int ans=0;
    for(int i=0;i<v.size();++i)
    {
        ans+=(v[i]*i-s);
        s+=v[i];
    }
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    //vector <pair<int,int> > z1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        //z1[i]={a[i],i};
    }
    vector <int> b(n);
    //vector <pair<int,int> > z2(n);
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
        //z2[i]=({b[i],i});
    }
    /*int sum=0;
    for(int i=0;i<keys.size();++i)
    {
        sum+=go2(u[keys[i]]);
    }*/
    vector <pair<int,int> > v(n);
    for(int i=0;i<n;++i)
    {
        v[i]={a[i],b[i]};
    }
    sort(v.begin(),v.end(),comp);
    vector <int> t(n);
    for(int i=0;i<n;++i)
    {
        t[i]=v[i].first;
    }
    /*for(int i=0;i<t.size();++i)
    {
        cout<<t[i]<<" ";
    }
    cout<<endl;*/
    //build(t);
    int ans=0;
    cout<<go(t)<<endl;
    return 0;
}