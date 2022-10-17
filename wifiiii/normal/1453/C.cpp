#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

char a[2005][2005];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i)for(int j=0;j<n;++j) a[i][j]-='0';
        vector<int> ans(10);
        {
            vector<int> colmn(10),colmx(10);
            for(int i=0;i<10;++i) colmn[i]=1e9,colmx[i]=-1e9;
            vector<vector<int>> rowmn(n,vector<int>(10));
            vector<vector<int>> rowmx(n,vector<int>(10));
            for(int i=0;i<n;++i) for(int j=0;j<10;++j) rowmn[i][j]=1e9,rowmx[i][j]=-1e9;
            for(int i=0;i<n;++i) {
                for(int j=0;j<n;++j) {
                    rowmn[i][a[i][j]] = min(rowmn[i][a[i][j]], j);
                    rowmx[i][a[i][j]] = max(rowmx[i][a[i][j]], j);
                    colmn[a[i][j]] = min(colmn[a[i][j]], i);
                    colmx[a[i][j]] = max(colmx[a[i][j]], i);
                }
            }
            for(int i=0;i<10;++i) {
                for(int j=0;j<n;++j) {
                    if(rowmn[j][i] <= rowmx[j][i]) {
                        int d = max(n-1-rowmn[j][i], rowmx[j][i]);
                        int h1 = j - colmn[i], h2 = colmx[i] - j;
                        ans[i] = max(ans[i], d * h1);
                        ans[i] = max(ans[i], d * h2);
                    }
                }
            }
        }
        for(int i=0;i<n;++i) {
            for(int j=i;j<n;++j) {
                swap(a[i][j],a[j][i]);
            }
        }
        {
            vector<int> colmn(10),colmx(10);
            for(int i=0;i<10;++i) colmn[i]=1e9,colmx[i]=-1e9;
            vector<vector<int>> rowmn(n,vector<int>(10));
            vector<vector<int>> rowmx(n,vector<int>(10));
            for(int i=0;i<n;++i) for(int j=0;j<10;++j) rowmn[i][j]=1e9,rowmx[i][j]=-1e9;
            for(int i=0;i<n;++i) {
                for(int j=0;j<n;++j) {
                    rowmn[i][a[i][j]] = min(rowmn[i][a[i][j]], j);
                    rowmx[i][a[i][j]] = max(rowmx[i][a[i][j]], j);
                    colmn[a[i][j]] = min(colmn[a[i][j]], i);
                    colmx[a[i][j]] = max(colmx[a[i][j]], i);
                }
            }
            for(int i=0;i<10;++i) {
                for(int j=0;j<n;++j) {
                    if(rowmn[j][i] <= rowmx[j][i]) {
                        int d = max(n-1-rowmn[j][i], rowmx[j][i]);
                        int h1 = j - colmn[i], h2 = colmx[i] - j;
                        ans[i] = max(ans[i], d * h1);
                        ans[i] = max(ans[i], d * h2);
                    }
                }
            }
        }
        for(int i=0;i<10;++i) cout<<ans[i]<<" ";
        cout<<endl;
    }
}