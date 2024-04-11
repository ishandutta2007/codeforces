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
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'

int nxt[10005];
int main() {
    int t;
    cin>>t;
    while(t--) {
        memset(nxt,0,sizeof(nxt));
        int n;
        cin>>n;
        if(n<=3) {
            cout<<-1<<endl;
            continue;
        }
        int S=2,T=3;
        nxt[2]=4,nxt[4]=1,nxt[1]=3;
        for(int i=5;i<=n;++i) {
            if(abs(i-S)<2) {
                nxt[T]=i, T=i;
            } else if(abs(i-T)<2) {
                nxt[i]=S, S=i;
            }
            else {
                if(S < T) nxt[i]=S, S=i;
                else nxt[T]=i, T=i;
            }
        }
        for(int i=S;i;i=nxt[i]) cout<<i<<" ";cout<<endl;
    }
}