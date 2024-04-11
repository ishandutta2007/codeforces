#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> v;
vector <int> z;
void get(vector <int> ans)
{
    cout<<"! ";
    vector <int> ans1(ans.size());
    for(int i=0;i<ans.size();++i)
    {
        ans1[v[i]]=ans[i];
    }
    for(auto h:ans1) cout<<h<<' ';
    cout<<endl;
}
int lcm(int x,int y)
{
    return (x*y)/__gcd(x,y);
}
int query(int i,int j)
{
    i=v[i];j=v[j];
    cout<<"? "<<i+1<<' '<<j+1<<endl;
    int res;
    //res=lcm(z[i],z[j]);
    cin>>res;
    return res;
}
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1) return v;
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v=rasl(x/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(x);
    return v;
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
        //z.clear();
        //for(int i=0;i<n;++i) {int x;cin>>x;z.push_back(x);}
        v.clear();
        for(int i=0;i<n;++i)
        {
            v.push_back(i);
        }
        shuffle(v.begin(),v.end(),default_random_engine(65432));
        vector <int> ans(n);for(int i=0;i<n;++i) ans[i]=0;
        if(n==3)
        {
            for(int i=0;i<n;++i)
            {
                for(int j=(i+1);j<n;++j)
                {
                     {
                         int res1=query(i,j);
                         ans[i]=__gcd(ans[i],res1);
                         ans[j]=__gcd(ans[j],res1);
                     }
                }
            }
            if(*max_element(ans.begin(),ans.end())-*min_element(ans.begin(),ans.end())==2)
            {
                get(ans);
            }
            else
            {
                ans[max_element(ans.begin(),ans.end())-ans.begin()]/=2;
                get(ans);
            }
            continue;
        }
        if(n<100)
        {
            for(int i=0;i<n;++i)
            {
                for(int j=(i+1);j<n;++j)
                {
                     {
                         int res1=query(i,j);
                         ans[i]=__gcd(ans[i],res1);
                         ans[j]=__gcd(ans[j],res1);
                     }
                }
            }
            get(ans);
            continue;
        }
        vector <pair<int,int> > h;
        for(int i=0;i<n;++i)
        {
            int ans1=0;
            for(int j=(i+1);j!=i && j<(i+50);j=(j+1)%n)
            {
                ans1=__gcd(ans1,query(i,j));
            }
            vector <int> z=rasl(ans1);
            ans[i]=ans1;
            if(z.size()==1 && z[0]>90)
            {
                h.push_back({i,ans1});
            }
            if(h.size()>=2) break;
        }
        int ma=(ans[0]+n)/90;
        for(int i=0;i<n;++i)
        {
            if(ans[i]==0)
            {
                 int ans1=query(i,h[0].first);
                 if(ans1>(ma*h[0].second))
                 {
                     ans[i]=ans1/h[0].second;
                     continue;
                 }
                 else
                 {
                 int ans2=query(i,h[1].first);
                 ans[i]=__gcd(ans1,ans2);
                 }
            }
        }
        get(ans);
    }
    return 0;
}