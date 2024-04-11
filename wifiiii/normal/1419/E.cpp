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
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int x,y;
        cin>>x;y=x;
        vector<int> v;
        for(int i=2;i*i<=x;++i) {
            if(x%i==0) {
                v.push_back(i);
                if(i*i!=x) v.push_back(x/i);
            }
        }
        if(v.size() == 2 && gcd(v[0],v[1])==1) {
            cout << v[0] << " " << v[1] << " " << v[0]*v[1] << endl;
            cout << 1 << endl;
        } else {
            vector<int> p,vis(v.size());
            for(int i=2;i*i<=x;++i) {
                if(x%i==0) {
                    while(x%i==0) x/=i;
                    p.push_back(i);
                }
            }
            if(x>1) p.push_back(x);
            int pcnt=p.size();
            for(int i=0;i<pcnt;++i) {
                cout<<p[i]<<" ";
                for(int j=0;j<v.size();++j) {
                    if(p[i] == v[j] || v[j] == p[i]*p[i+1]) vis[j]=1;
                    if(vis[j]) continue;
                    if(v[j] % p[i] == 0) {
                        vis[j]=1;
                        cout<<v[j]<<" ";
                    }
                }
                if(i+1<pcnt) cout<<p[i]*p[i+1]<<" ";
            }
            cout<<y<<endl;
            cout << 0 << endl;
        }
    }
}