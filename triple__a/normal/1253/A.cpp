#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/
int n,t,a[200007],b[200007];

int main(){
    cin>>t;
    while (t--){
        cin>>n;
        rep(i,n) cin>>a[i];
        rep(i,n) cin>>b[i];
        int i=0,k;
        while (i<n){
            if (a[i]!=b[i]) break;
            ++i;
        }
        a[n]=b[n]=0;
        k=b[i]-a[i];
        if (k<0){
            cout<<"NO"<<endl;
            continue;
        }
        while (i<n){
            if (b[i]-a[i]!=k) break;
            ++i;
        }
        while (i<n){
            if (b[i]!=a[i]) break;
            i++;
        }
        if (i<n){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}