#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;
typedef long long ll;
int u[maxn],v[maxn];
ll w[maxn],ans[maxn];
set<int> m,p;
int n,mi;
vector<tuple<int,int,ll> >vec;
int main(){
    scanf("%d%d",&n,&mi);
    for (int i=1;i<=mi;++i){
        scanf("%d%d%lld",&u[i],&v[i],&w[i]);
        ans[u[i]]+=w[i], ans[v[i]]-=w[i];
    }
    for (int i=1;i<=n;++i){
        if (ans[i]<0) m.insert(i);
        if (ans[i]>0) p.insert(i);
    }
    while (m.size()&&p.size()){
        int x=*m.begin(),y=*p.begin();
        if (-ans[x]<ans[y]){
            vec.push_back({y,x,-ans[x]});
            m.erase(x);
            ans[y]+=ans[x];
        }
        else{
            vec.push_back({y,x,ans[y]});
            p.erase(y);
            ans[x]+=ans[y];
            if (ans[x]==0){
                m.erase(x);
            }
        }
    }
    printf("%d\n",vec.size());
    for (auto c:vec){
        int u,v;
        long long w;
        tie(u,v,w)=c;
        printf("%d %d %lld\n",u,v,w);
    }
    return 0;
}