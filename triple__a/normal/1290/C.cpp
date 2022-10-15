#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=600007;

int n,k,p[maxn],ans[maxn],ret;
string s;
vector<int> land[maxn];
int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u), pv=find(v);
    if (pu!=pv){
        p[pu]=pv;
        ans[pv]+=ans[pu];
    }
    return pu!=pv;
}

int calc(int u){
    return ans[find(u)];
}

#undef int 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k>>s;
    for (int i=0;i<k;++i){
        int u;
        cin>>u;
        while (u--){
            int w;
            cin>>w;
            land[w-1].push_back(i);
        }
    }
    for (int i=0;i<k;++i){
        p[2*i]=2*i, p[2*i+1]=2*i+1;
        ans[2*i]=0, ans[2*i+1]=1;
    }
    for (int i=0;i<n;++i){
        if (land[i].size()==1){
            int u=land[i][0]<<1;
            if (s[i]=='1') u++;
            if (calc(u)<calc(u^1)) ret+=calc(u^1)-calc(u);
            ans[find(u)]=1000000; 
        }
        if (land[i].size()==2){
            int u=land[i][0]<<1, v=land[i][1]<<1;
            if (s[i]=='0') v^=1;
            long long tmp=min(calc(u),calc(u^1))+min(calc(v),calc(v^1));
            bool fg1=unite(u,v);
            bool fg2=unite(u^1,v^1);
            if (fg1&&fg2){
                ret+=min(calc(u),calc(u^1))-tmp;
            }
        }
        cout<<ret<<"\n";
    }
    return 0;
}