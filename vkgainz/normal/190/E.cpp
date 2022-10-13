#include <bits/stdc++.h>
using namespace std;
#define ll long long
set<int> curr;
set<int> rem;
struct dsu{
    int sz[500000+1];
    int par[500000+1];
    void init(int n){
        for(int i=0;i<n;i++){
            sz[i] = 1;
            par[i] = i;
        }
    }
    int find(int x){
        if(x==par[x]) return x;
        return par[x] = find(par[x]);
    }
    void merge(int a,int b){
        int x = find(a);
        int y= find(b);
        if(x==y) return;
        if(sz[x]<sz[y]){
            swap(x,y);
        }
        rem.insert(y);
        sz[x]+=sz[y];
        par[y] = x;
    }
};
vector<vector<int>> adj;
map<int,int> l; 
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) adj.push_back(vector<int>());
    for(int i=0;i<m;i++){
        int x,y; scanf("%d%d",&x,&y);
        --x; --y;
        if(x<y) swap(x,y);
        adj[x].push_back(y);
    }
    dsu x;
    x.init(n);
    for(int i=0;i<n;i++){
        l.clear();
        rem.clear();
        curr.insert(i);
        for(int j : adj[i])
            ++l[x.find(j)];
        for(auto &it : curr){
            if(l[it]!=x.sz[it]){
                x.merge(i,it);
            }
        }
        for(auto &it : rem)
            curr.erase(it);
    }
    vector<vector<int>> comp;
    for(int i=0;i<n;i++) comp.push_back(vector<int>());
    for(int i=0;i<n;i++){
        comp[x.find(i)].push_back(i);
    }
    cout << curr.size() << endl;
    for(auto &it : comp){
        if(it.size()>0){
            printf("%d ",it.size());
        for(auto &it : it){
            printf("%d ",(it+1));
        }
        printf("\n");
        }
    }
}