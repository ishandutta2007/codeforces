#include<bits/stdc++.h>

using namespace std;

const int maxn=1000007;
pair<int,int> e[maxn];

int p[maxn],n,ans=0;
set<pair<int,int> >s;


int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int px=find(u),py=find(v);
    p[py]=px;
    return px!=py;
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d%d",&e[i].first,&e[i].second),p[i]=i;
    sort(e,e+n);
    for (int i=0;i<n;++i){
        while (s.size()&&(*s.begin()).first<e[i].first) s.erase(s.begin());
        for (auto c:s){
            if (c.first>e[i].second) break;
            if (!unite(c.second,i)){
                puts("NO");
                return 0;
            }
            ans++;
        }
        s.insert({e[i].second,i});
    }
    if (ans==n-1){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}