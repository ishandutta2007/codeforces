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

const int maxn=4000007;
const int mod=1e9+7; 
int n,x,t;
char s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while (t--){
        cin>>x;
        cin>>s;
        int u=strlen(s),tmp=u,l=0;
        while (l<u&&u<x){
            int rem=u;
            for (int j=1;j<s[l]-'0';++j){
                for (int k=l+1;k<rem;++k){
                    s[u++]=s[k];
                }
            }
            l++;
        }
 //       cout<<s<<endl;
        long long now=tmp;
        for (int i=0;i<x;++i){
            now--;
            now=((s[i]-'0')*now)%mod;    
        }
        cout<<(now+x)%mod<<endl;
    }
    return 0;
}