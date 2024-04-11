#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,q,a[N],b[N],fa[N<<2],ans[N],siz[N<<2];
struct que{
    int k,num;
    bool operator<(const que bb)const{
        return k>bb.k;
    }
};
struct fi{
    int val,num;
    bool operator<(const fi bb)const{
        return val>bb.val;
    }
};
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[x]=y;siz[y]+=siz[x];}
signed main(){
    scanf("%lld%lld%lld",&n,&m,&q);
    for(int i=1;i<(N<<1);i++)fa[i]=i;
    vector<int>v;
    int an=0; 
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        an+=a[i];
        v.push_back(a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&b[i]);
        v.push_back(b[i]);
    }
    sort(v.begin(),v.end());
    vector<int>vv=v;
    v.erase(unique(v.begin(),v.end()),v.end());
    priority_queue<fi>qq;
    priority_queue<que>qu;
    for(int i=1;i<=q;i++){
        que u;
        scanf("%lld",&u.k);
        u.num=i;
        qu.push(u);
    }
    for(int i=0;i<(int)v.size()-1;i++){
        qq.push((fi){v[i+1]-v[i],i});
    }
    vector<int>vvv=vv;
    for(int i=1;i<(int)vvv.size();i++){
        vvv[i]+=vvv[i-1];
    }
    for(int i=1;i<=n;i++){
        siz[lower_bound(v.begin(),v.end(),a[i])-v.begin()]++;
    }
    while(qu.size()){
        que now=qu.top();
        qu.pop();
        while(qq.size()&&qq.top().val<=now.k){
            int xx=find(qq.top().num),yy=find(qq.top().num+1);
            int n1=upper_bound(vv.begin(),vv.end(),v[xx])-vv.begin()-1,n2=upper_bound(vv.begin(),vv.end(),v[yy])-vv.begin()-1;
            an-=vvv[n1]-((n1-siz[xx])==-1?0:vvv[n1-siz[xx]]);
            an+=vvv[n2-siz[yy]]-((n2-siz[yy]-siz[xx])==-1?0:vvv[n2-siz[yy]-siz[xx]]);
            unnion(xx,yy);
            qq.pop();
        }
        ans[now.num]=an;
    }
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return  0;
}