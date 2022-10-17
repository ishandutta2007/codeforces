#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn =200005;
int a[maxn];
int main() {
    int n,k;
    cin>>n>>k;
    ii cin>>a[i];
    if(k==1) {
        int ans=1e9;
        ii ans=min(ans,a[i]);
        cout<<ans<<endl;
    }
    else if(k%2==0) {
        // 1~n-1 find k/2
        int p=k/2;
        int lo=1,hi=1e9;
        while(lo<hi) {
            int mid=lo+hi>>1;
            int cnt=0,lst=-1;
            for(int i=1;i<=n-1;++i) {
                if(a[i]<=mid && i-lst>1) {
                    ++cnt,lst=i;
                }
            }
            if(cnt>=p) hi=mid;
            else lo=mid+1;
        }
        int ans=lo;
        // 2~n find k/2
        lo=1,hi=1e9;
        while(lo<hi) {
            int mid=lo+hi>>1;
            int cnt=0,lst=-1;
            for(int i=2;i<=n;++i) {
                if(a[i]<=mid && i-lst>1) {
                    ++cnt,lst=i;
                }
            }
            if(cnt>=p) hi=mid;
            else lo=mid+1;
        }
        ans=min(ans,lo);
        cout<<ans<<endl;
    } else {
        // 1~n find k/2+1
        int p=k/2+1;
        int lo=1,hi=1e9;
        while(lo<hi) {
            int mid=lo+hi>>1;
            int cnt=0,lst=-1;
            for(int i=1;i<=n;++i) {
                if(a[i]<=mid && i-lst>1) {
                    ++cnt,lst=i;
                }
            }
            if(cnt>=p) hi=mid;
            else lo=mid+1;
        }
        int ans=lo;
        // 2~n-1 find k/2
        p=k/2;
        lo=1,hi=1e9;
        while(lo<hi) {
            int mid=lo+hi>>1;
            int cnt=0,lst=-1;
            for(int i=2;i<=n-1;++i) {
                if(a[i]<=mid && i-lst>1) {
                    ++cnt,lst=i;
                }
            }
            if(cnt>=p) hi=mid;
            else lo=mid+1;
        }
        ans=min(ans,lo);
        cout<<ans<<endl;
    }
}