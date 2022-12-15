#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int MN = 1e5+5, MM = 2e5+5;
const long double eps = 1e-17, eps2 = 0.5;
int N, M, i, j, x, y, w, vs[MN], fl; double ans[MN];
vector<pii> adj[MN], vec[MN];
vector<int> cmp;
set<long double> sol;

void dfs(int n){
    vs[n]=1;
    cmp.push_back(n);
    for(auto v : adj[n]){
        vec[v.first].push_back({-vec[n][0].first,v.second-vec[n][0].second});
        if(vs[v.first]) continue;
        else dfs(v.first);
    }
}

inline long double inte(pii ln, pii ln2){
    return (long double)(ln2.second-ln.second)/(long double)(ln.first-ln2.first);
}

inline long double eval(pii ln, long double x){
    return (long double)ln.first*x+ln.second;
}

int main(){
    scanf("%d%d",&N,&M);
    for(i=1;i<=M;i++){
        scanf("%d%d%d",&x,&y,&w);
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    for(i=1;i<=N;i++){
        if(vs[i]) continue;
        cmp.clear();
        sol.clear();
        vec[i].push_back({1,0});
        dfs(i);
        for(auto u : cmp){
            for(j=1;j<(int)vec[u].size();j++){
                if(vec[u][j]!=vec[u][0]){
                    if(vec[u][j].first==vec[u][0].first){fl=1; break;}
                    else sol.insert(inte(vec[u][0],vec[u][j]));
                }
            }
        }
        if(sol.size()>=2){fl=1; break;}
        else if(sol.size()==1){
            double x = *sol.begin();
            for(auto u : cmp){
                for(j=1;j<(int)vec[u].size();j++){
                    if(eval(vec[u][0],x)!=eval(vec[u][j],x)){
                        fl=1; break;
                    }
                }
                ans[u]=eval(vec[u][0],x);
            }
        }
        else{
            int lo = -2*MM, hi = 2*MM, mid;
            long double ans1, ans2;
            while(lo<hi){
                mid = floor((lo+hi)/2.0);
                ans1 = ans2 = 0;
                for(auto u : cmp){
                    ans1 += abs(eval(vec[u][0],mid*eps2));
                    ans2 += abs(eval(vec[u][0],(mid+1)*eps2));
                }
                if(ans2>ans1) hi=mid;
                else lo=mid+1;
            }
            for(auto u : cmp){
                ans[u]=eval(vec[u][0],lo*eps2);
            }
        }
    }
    if(fl) printf("NO\n");
    else{
        printf("YES\n");
        for(i=1;i<=N;i++)
            printf("%.9lf ",ans[i]);
        printf("\n");
    }
    return 0;
}