#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back


int a[200005], b[400005], cnt[400005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i=1;i<=n;++i) cin>>a[i];
        {
            ll sum = 0;
            for(int i=1;i<=n;++i) sum+=a[i];
            if(sum+1-2*n < k) {
                cout << -1 << endl;
                continue;
            }
        }
        sort(a+1, a+1+n);

        cnt[0]++;
        int cur=0,tot=1,ans=0;
        for(int i=n;i>=1;--i) {
            int x=a[i];
            while(!cnt[cur]) {
                b[cur+1]+=b[cur];
                cnt[cur+1]=b[cur+1];
                tot+=b[cur+1];
                ++cur;
            }
            if(tot>=k) break;
            if(tot+b[cur]+b[cur+1]>=k) {
                tot=k;
                ++cur;
                break;
            }
            --cnt[cur]; --x; --tot;
            b[cur+2] += 2;
            if(x % 2 == 0) {
                b[cur+2+x/2] -= 2;
            } else {
                b[cur+2+x/2] -= 1;
                b[cur+3+x/2] -= 1;
            }
        }
        while(tot < k) {
            b[cur+1] += b[cur];
            tot += b[cur+1];
            ++cur;
        }
        cout<<cur<<endl;
    }
}