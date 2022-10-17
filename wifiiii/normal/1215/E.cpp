#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 400005;
int a[maxn];
int cnt[55];
ll dp[(1<<20)+5],ex[44][44];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    int len = unique(v.begin(),v.end()) - v.begin();
    for(int i=1;i<=n;++i) a[i]=lower_bound(v.begin(),v.begin()+len,a[i])-v.begin();
    for(int i=1;i<=n;++i) cnt[a[i]]++;
    for(int i=0;i<len;++i) {
        for(int j=0;j<len;++j) {
            int tot=cnt[i];
            if(i==j) continue;
            for(int k=1;k<=n;++k) {
                if(a[k]==i) tot--;
                else if(a[k]==j) {
                    ex[i][j] += tot;
                }
            }
        }
    }
//    for(int i=0;i<len;++i) {
//        for(int j=0;j<len;++j)
//            cout<<ex[i][j]<<" ";
//        cout<<endl;
//    }
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<(1<<len);++i)
    {
        for(int j=0;j<len;++j)
        {
            if(i & (1<<j))
            {
                ll cost = 0;
                for(int k=0;k<len;++k)
                    if(j!=k && !(i&(1<<k))) cost += ex[j][k];
                dp[i] = min(dp[i], dp[i^(1<<j)] + cost);
            }
        }
    }
    cout << dp[(1<<len)-1] << endl;
}