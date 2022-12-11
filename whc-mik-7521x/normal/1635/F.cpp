#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
struct BIT{
    long long ts[N];
    long long ask(long long x){
        long long res=4e18+114514;
        for(;x;x-=x&-x)res=min(ts[x],res);
        return res;
    }
    void add(long long x,long long d){
        for(;x<N;x+=x&-x)ts[x]=min(d,ts[x]);
    }
    void init(){
        for(long long i=1;i<N;i++)ts[i]=4e18+114514;
    }
}tr;
long long n,q,a[N],w[N],ans[N];
struct segment{
    long long tp,num;
    long long l,r;
    long long w;
    bool operator<(const segment b)const{
        return l==b.l?tp>b.tp:l<b.l;
    }
};
int main(){
    scanf("%lld%lld",&n,&q);
    stack<long long>s;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i],&w[i]);
    }
    vector<segment>qo;
    for(int i=1;i<=n;i++){
        while(s.size()&&w[s.top()]>w[i])s.pop();
        if(s.size())qo.push_back({1,0,a[s.top()],a[i],(a[i]-a[s.top()])*(w[i]+w[s.top()])});
        s.push(i);
    }
    while(s.size())s.pop();
    for(int i=n;i>=1;i--){
        while(s.size()&&w[s.top()]>w[i])s.pop();
        if(s.size())qo.push_back({1,0,a[i],a[s.top()],(a[s.top()]-a[i])*(w[i]+w[s.top()])});
        s.push(i);
    }
    for(int i=1;i<=q;i++){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        qo.push_back({2,i,a[x],a[y],0});
    }
    vector<int>v;
    for(auto it:qo)v.push_back(it.l),v.push_back(it.r);
    stable_sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<(int)qo.size();i++){
        qo[i].l=lower_bound(v.begin(),v.end(),qo[i].l)-v.begin()+1;
        qo[i].r=lower_bound(v.begin(),v.end(),qo[i].r)-v.begin()+1;
    }
    stable_sort(qo.begin(),qo.end());
    tr.init();
    for(auto it=qo.rbegin();it!=qo.rend();it++){
        segment now=*it;
        if(now.tp==1){
            tr.add(now.r,now.w);
        }
        else{
            ans[now.num]=tr.ask(now.r);
        }
    }
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return  0;
}