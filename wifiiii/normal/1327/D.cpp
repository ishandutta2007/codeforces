#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[200005],c[200005],vis[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ii cin>>a[i];
        ii cin>>c[i];
        ii vis[i]=0;
        int ans = 1e9;
        ii
        {
            if(vis[i]) continue;;
            vector<int> v;
            int cur = a[i];
            v.push_back(i);
            while(cur != i) {
                v.push_back(cur);
                vis[cur] = 1;
                cur = a[cur];
            }
            int m = v.size();
            for(int i=1;i*i<=m;++i)
            {
                if(m%i==0)
                {
                    int tmp = i;
                    if(ans > tmp)
                    {
                        int okk = 0;
                        for(int k=0;k<tmp;++k) {
                            int ok = 1;
                            for(int q=k+tmp;q<m;q+=tmp) if(c[v[q]] != c[v[k]]) {ok = 0; break;}
                            if(ok) {okk = 1; break;}
                        }
                        if(okk) ans = min(ans, tmp);
                    }
                    if(i != m / i)
                    {
                        tmp = m / i;
                        if(ans > tmp)
                        {
                            int okk = 0;
                            for(int k=0;k<tmp;++k) {
                                int ok = 1;
                                for(int q=k+tmp;q<m;q+=tmp) if(c[v[q]] != c[v[k]]) {ok = 0; break;}
                                if(ok) {okk = 1; break;}
                            }
                            if(okk) ans = min(ans, tmp);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}