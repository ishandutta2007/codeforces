#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
struct seg{
    int t[N<<2];
    seg(){memset(t,0,sizeof t);}
    void pushup(int rt){t[rt]=max(t[rt<<1],t[rt<<1|1]);}
    void upd(int rt,int l,int r,int X,int d){
        if(l==r)return t[rt]=d,void();
        int mid=(l+r)>>1;
        if(X<=mid)upd(rt<<1,l,mid,X,d);
        else upd(rt<<1|1,mid+1,r,X,d);
        pushup(rt);
    }
    int query(int rt,int l,int r,int L,int R){
        if(L>R)return 0;
        if(L<=l&&r<=R)return t[rt];
        int mid=(l+r)>>1,res=0;
        if(L<=mid)res=max(res,query(rt<<1,l,mid,L,R));
        if(R>mid)res=max(res,query(rt<<1|1,mid+1,r,L,R));
        return res;
    }
}tr1,tr2;
int n,m,h[N];
struct node{
    int x,num;
    bool operator<(const node b)const{
        return x<b.x;
    }
};
set<node>st1,st2;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int tp;
        scanf("%d",&tp);
        if(tp==1){
            int x,y;
            scanf("%d%d",&x,&y);
            h[x]=y-i+m;
            vector<int>del;
            while(st1.begin()!=st1.end()&&st1.begin()->x<h[x]){
                tr1.upd(1,1,n,st1.begin()->num,0);
                del.push_back(st1.begin()->num);
                st1.erase(st1.begin());
            }
            int val=tr1.query(1,1,n,x+1,n)+1;
            tr1.upd(1,1,n,x,val),tr2.upd(1,1,m+10,h[x],val);
            st1.insert(node{h[x],x});
            st2.insert(node{x,x});
            reverse(del.begin(),del.end());
            for(int o:del){
                val=tr1.query(1,1,n,o+1,n)+1;
                tr1.upd(1,1,n,o,val),tr2.upd(1,1,m+10,h[o],val);
                st1.insert(node{h[o],o});
            }
        }
        else{
            int x;
            scanf("%d",&x);
            vector<int>del;
            for(int o=1;o<x;o++){
                del.push_back(st2.begin()->num);
                tr2.upd(1,1,m+10,h[st2.begin()->num],0);
                st2.erase(st2.begin());
            }
            x=st2.begin()->num;
            tr1.upd(1,1,n,x,0),tr2.upd(1,1,m+10,h[x],0);
            st1.erase(node{h[x],x});
            st2.erase(st2.begin());
            reverse(del.begin(),del.end());
            for(int o:del){
                int val=tr2.query(1,1,m+10,h[o]+1,m+10)+1;
                tr1.upd(1,1,n,o,val),tr2.upd(1,1,m+10,h[o],val);
                st2.insert(node{o,o});
            }
        }
        printf("%d\n",tr1.query(1,1,n,1,n));
    }
    return  0;
}