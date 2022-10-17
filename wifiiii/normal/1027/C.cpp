#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int cnt[10005];
int a[1000005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=1;i<=n;++i) cin>>a[i];
        int f = 0;
        ii
        {
            cnt[a[i]]++;
            if(cnt[a[i]] % 2 == 0) v.push_back(a[i]);
            if(cnt[a[i]] == 4) f = a[i];
        }
        if(f) cout<<f<<" "<<f<<" "<<f<<" "<<f<<endl;
        else{
            sort(all(v));
            double ans = 1e18;
            int x=0,y=0;
            for(int i=0;i<v.size()-1;++i)
            {
                double tmp = 1.0*v[i]/v[i+1]+1.0*v[i+1]/v[i];
                if(tmp < ans) ans = tmp, x = v[i], y = v[i+1];
            }
            cout << x << " " << x << " " << y << " " << y << endl;
        }
        ii cnt[a[i]]--;
    }
}