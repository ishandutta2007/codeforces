#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
int a[100001], b[100001];
set<int> vals[100001];
struct dsu{
    int parent[100001], sz[100001];
    void init(){
        for(int i=0;i<100001;i++)
            parent[i] = i, sz[i] = 1;
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x,int y){
        int a = find(x), b = find(y);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            sz[a]+=sz[b], parent[b] = a;
        }
    }
};
bool cmp(const pair<int,int> &x, const pair<int,int> &y){
    if(a[x.f]+b[x.s]==a[y.f]+b[y.s]) return x<y;
    return a[x.f]+b[x.s]>a[y.f]+b[y.s];
}
int main(){
    int m,n;
    cin >> m >> n;
    for(int i=0;i<m;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    set<pair<int,int>,decltype(cmp)*> s(cmp);
    for(int i=0;i<m;i++){
        int num; cin >> num;
        for(int j=0;j<num;j++) {
            int x; cin >> x;
            s.insert({i,x-1});
        }
    }
    ll ans = 0;
    dsu x;
    x.init();
    
    for(auto &it : s){
        int bucket = it.f;
        int val = it.s;
        auto next = vals[bucket].begin();
        if(next!=vals[bucket].end()){ 
            if(x.find(val)==x.find((*next))){
                ans+=a[bucket]+b[val];
            }
            else {
                x.merge(val,(*next));
            }
        }
        vals[bucket].insert(val);
    }
    cout << ans << endl;
}