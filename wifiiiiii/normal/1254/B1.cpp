#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[100005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ii cin>>a[i];
    ii a[i]+=a[i-1];
    int tot=a[n];
    if(tot==1) return cout<<-1<<endl,0;
    if(tot==0) return cout<<0<<endl,0;
    ll ans = 1e18;
    {
        vector<int> v;
        for(int i=1;i<=n;++i) if(a[i]!=a[i-1]) v.push_back(i);
        int mid=v[v.size()/2];
        ll tmp=0;
        for(int i:v) tmp+=abs(mid-i);
        ans=min(ans,tmp);
    }
    for(int i=2;i*i<=tot;++i)
    {
        if(tot % i == 0)
        {
            int d = i;
            vector<int> v;
            int last = 1;
            ll tmp = 0;
            for(int j=1;j<=n;++j)
            {
                if(a[j] % d == 0 && a[j] != a[j-1])
                {
                    for(int k=last;k<=j;++k)
                        if(a[k] != a[k-1]) v.push_back(k);
                    int mid=v[v.size()/2];
                    for(int i:v) tmp+=abs(mid-i);
                    last = j+1;
                    v.clear();
                }
            }
            ans=min(ans,tmp);
            d = tot / i;
            if(d != i)
            {
                vector<int> v;
                int last = 1;
                ll tmp = 0;
                for(int j=1;j<=n;++j)
                {
                    if(a[j] % d == 0 && a[j] != a[j-1])
                    {
                        for(int k=last;k<=j;++k)
                            if(a[k] != a[k-1]) v.push_back(k);
                        int mid=v[v.size()/2];
                        for(int i:v) tmp+=abs(mid-i);
                        last = j+1;
                        v.clear();
                    }
                }
                ans=min(ans,tmp);
            }
        }
    }
    cout<<ans<<endl;
}