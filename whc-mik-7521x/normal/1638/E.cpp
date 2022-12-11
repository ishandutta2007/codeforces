#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int tag[N],n,q;
struct BIT{
    int ts[N];
    int ask(int x){
        int res=0;
        for(;x;x-=x&-x)res+=ts[x];
        return res;
    }
    void add(int x,int d){
        for(;x<N;x+=x&-x)ts[x]+=d;
    }
}tr;
struct node{
    int l,r,col;
    bool operator<(const node b)const{
        return l<b.l;
    }
};
struct odt{
    set<node>st;
    auto split(int x){
        if(x>n)return st.end();
        auto it=--st.upper_bound((node){x,0,0});
        if(it->l==x)return it;
        int l=it->l,r=it->r,col=it->col;
        st.erase(it);
        st.insert((node){l,x-1,col});
        return st.insert((node){x,r,col}).first;
    }
    void assign(int l,int r,int col){
        auto itr=split(r+1),itl=split(l);
        for(auto it=itl;it!=itr;it++){
            tr.add(it->l,(tag[it->col]-tag[col]));
            tr.add((it->r)+1,-(tag[it->col]-tag[col]));
        }
        st.erase(itl,itr);
        st.insert((node){l,r,col});
    }
    int query(int x){
        return tr.ask(x)+tag[(--st.upper_bound((node){x,0,0}))->col];
    }
}odtr;
signed main(){
    scanf("%lld%lld\n",&n,&q);
    odtr.st.insert((node){1,n,1});
    while(q--){
        char s[100];
        scanf("%s",s);
        if(s[0]=='C'){
            int l,r,col;
            scanf("%lld%lld%lld",&l,&r,&col);
            odtr.assign(l,r,col);
        }
        if(s[0]=='A'){
            int col,x;
            scanf("%lld%lld",&col,&x);
            tag[col]+=x;
        }
        if(s[0]=='Q'){
            int x;
            scanf("%lld",&x);
            printf("%lld\n",odtr.query(x));
        }
    }
    return  0;
}