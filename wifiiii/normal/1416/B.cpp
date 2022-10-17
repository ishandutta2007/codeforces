#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 10005;
int a[maxn];
struct node {
    int i,j,x;
};
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int s=0;
        ii cin>>a[i],s+=a[i];
        if(s%n) {cout<<-1<<endl;continue;}
        s/=n;
        vector<node> ans;
        for(int i=2;i<=n;++i) {
            if(a[i]/i) {
                int x=a[i]/i;
                a[i]-=x*i;
                a[1]+=x*i;
                ans.push_back({i,1,x});
            }
        }
        int ok=1;
        for(int i=2;i<=n;++i) {
            if(a[i]>s) {
                while(a[1]<i-a[i]) {
                    int mx=0,mj=0;
                    for(int j=2;j<=n;++j) {
                        if(a[1]>=j-a[j]){
                            if(a[j]>mx) {
                                mx=a[j];
                                mj=j;
                            }
                        }
                    }
                    if(!mx) {
                        ok=0;
                        break;
                    }
                    int x=mj-a[mj];
                    a[mj]+=x;
                    a[1]-=x;
                    ans.push_back({1,mj,x});
                    x=1;
                    a[mj]-=mj;
                    a[1]+=mj;
                    ans.push_back({mj,1,x});
                }
                int x=i-a[i];
                a[i]+=x;
                a[1]-=x;
                ans.push_back({1,i,x});
                x=1;
                a[i]-=i;
                a[1]+=i;
                ans.push_back({i,1,x});
            }
        }
        for(int i=2;i<=n;++i) {
            if(a[i]<s) {
                int x=s-a[i];
                a[i]+=x;
                a[1]-=x;
                ans.push_back({1,i,x});
            }
        }
        if(!ok) {cout<<-1<<endl;continue;}
        cout<<ans.size()<<endl;
        for(auto &u : ans) cout<<u.i<<" "<<u.j<<" "<<u.x<<endl;
    }
}