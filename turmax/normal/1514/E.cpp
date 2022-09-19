#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> mlv;
void getml()
{
    for(int i=0;i<100000000;++i) mlv.push_back(i);
}
int query(int a,int b)
{
    if(a==b) return 0;
    cout<<1<<' '<<a<<' '<<b<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int query2(int a,vector <int> v)
{
    cout<<2<<' ';
    cout<<a<<' ';
    cout<<v.size()<<' ';
    for(auto h:v) cout<<h<<' ';
    cout<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> v;
        v.push_back(0);
        for(int i=1;i<n;++i)
        {
            int low=(-1);
            int up=v.size();
            while(true)
            {
                if((up-low)==1) break;
                int mid=(low+up)/2;
                if(query(i,v[mid])) up=mid;
                else low=mid;
            }
            v.insert(v.begin()+up,i);
        }
        int r=v.size()-1;
        vector <pair<int,int> > ans;
        int currr=v.size()-1;
        for(int i=v.size()-1;i>=0;i--)
        {
            vector <int> z;
            for(int j=0;j<r;++j) z.push_back(v[j]);
            if(query2(v[i],z))
            {
                for(int j=(r-1);j>=0;j--)
                {
                    if(query(v[i],v[j]))
                    {
                         r=j;
                         z.clear();
                         for(int j=0;j<r;++j) z.push_back(v[j]);
                         if(!query2(v[i],z)) break;
                    }
                }
            }
            else if(i==r)
            {
                ans.push_back({r,currr});
                r--;
                currr=r;
                if(i==0) break;
            }
        }
        int res[n][n];
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) res[i][j]=0;
        for(int i=0;i<v.size();++i) for(int j=i;j<v.size();++j) res[v[i]][v[j]]=1;
        for(auto h:ans) for(int j=h.first;j<=h.second;++j) for(int k=h.first;k<=h.second;++k) res[v[j]][v[k]]=1;
        cout<<3<<endl;
        for(int i=0;i<n;++i) {for(int j=0;j<n;++j) cout<<res[i][j]; cout<<endl;}
        int res1;
        cin>>res1;
        if(res1==(-1)) {getml();}
    }
    return 0;
}