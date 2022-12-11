#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,q,pd[N],tow[N],nw[N],ct=1,cn,rt,ctr,son[N],sta[N],ed[N],bel[N],fa[N],fri[N];
struct BIT{
    long long ts[N];
    long long ask(int x){
        long long res=0;
        for(;x;x-=x&-x)res+=ts[x];
        return res;
    }
    void add(int x,long long d){
        for(;x<N;x+=x&-x)ts[x]+=d;
    }
    void del(int x){
        for(int i=0;i<=x;i++)ts[x]=0;
    }
}t,tt;
void build(int x){
    sta[x]=ct;
    bel[rt]=x;
    int now=0;
    vector<int>v;
    while(nw[++rt]){
        ++ct;
        son[x]++;
        fa[ct]=x;
        fri[ct]=++now;
        v.push_back(ct);
        build(ct);
    }
    for(int i=0;i<(int)v.size();i++){
        fri[v[i]]=ctr+i+1;
    }
    ctr+=v.size();
    bel[rt]=x;
    ed[x]=ct;
    t.add(x,((1ll*son[x]*(son[x]+1))>>1));
}
long long calc(int x){
    return (1ll*x*(x+1))>>1;
}
int main(){
    scanf("%d%d",&n,&q);
    string s;
    cin>>s;
    stack<int>st;
    for(int i=0;i<n;i++){
        if(s[i]=='(')st.push(i);
        else {
            if(st.size()){
                pd[i]=pd[st.top()]=1;
                st.pop();
            }
        }
    }
    for(int i=0;i<n;i++){
        if(pd[i])tow[i+1]=++cn,nw[cn]=(s[i]=='('?1:0);
    }
    t.del(n);
    nw[0]=1;
    build(1);
    for(int i=1;i<=ctr;i++)tt.add(i,1);
    while(q--){
        int tp,l,r;
        scanf("%d%d%d",&tp,&l,&r);
        l=tow[l],r=tow[r];
        if(tp==2){
            printf("%lld\n",t.ask(ed[bel[r]])-t.ask(sta[bel[l]]-1)+calc(tt.ask(fri[bel[r]])-tt.ask(fri[bel[l]]-1)));
        }
        else{
            int f=fa[bel[l]];
            t.add(f,-((1ll*son[f]*(son[f]+1))>>1));
            son[f]--;
            t.add(f,((1ll*son[f]*(son[f]+1))>>1));
            tt.add(fri[bel[l]],-1);
        }
    }
    return  0;
}