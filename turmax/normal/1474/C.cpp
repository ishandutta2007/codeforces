#include <bits/stdc++.h>

using namespace std;
vector <pair<int,int> > v;
bool go(vector <int>& a,int& x)
{
    int o=(x-a[a.size()-1]);
    //cout<<o<<" o "<<endl;
    //cout<<x<<" x "<<endl;
    int z=a[a.size()-1];
    //cout<<x<<" x "<<endl;
    //for(auto h:a) cout<<h<<" h "<<endl;
    a.pop_back();
    for(int i=0;i<a.size();++i)
    {
        if(a[i]==o)
        {
            v.push_back({a[i],x-o});
            a.erase(a.begin()+i);
            x=z;
            return true;
        }
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        v.clear();
        int n;
        cin>>n;
        n*=2;
        vector <int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a.begin(),a.begin()+n);
        vector <int> b=a;
        bool z=true;
        for(auto l:b)
        {
        //cout<<l<<" l "<<endl;
        a=b;
        v.clear();
        int curr=l+a.back();
        int curr1=curr;
        bool h=true;
        while(a.size()>=2)
        {
            if(!go(a,curr))
            {
                h=false;
                break;
            }
        }
        if(h)
        {
            cout<<"YES"<<endl;
            cout<<curr1<<endl;
            for(auto h:v) cout<<h.first<<' '<<h.second<<endl;
            z=false;
            break;
        }
        }
        if(z) cout<<"NO"<<endl;
    }
    return 0;
}