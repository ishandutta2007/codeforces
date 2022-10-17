#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)

struct node{
    node *l,*r;
    long long pr;
    int money, _money;
    int tshirt, _tshirt;
    int id;
    node(int m,int i){
        l=r=0;
        money=m;
        tshirt=_tshirt=_money=0;
        pr = rand();
        id=i;
    }
    node* set(node* _l, node* _r){
        l=_l,r=_r;
        return this;
    }
};
typedef node* np;

void push(np n){
    if(!n)return;
    int _money=n->_money, _tshirt=n->_tshirt;
    #define _push(t) if(t) t->money+=_money,t->_money+=_money,t->tshirt+=_tshirt,t->_tshirt+=_tshirt
    _push(n->l); _push(n->r);
    n->_money=n->_tshirt=0;
}

np merge(np l, np r){
    if(!(l&&r)) return l?l:r;
    push(l), push(r);
    if(l->pr > r->pr) return l->set(l->l,merge(l->r,r));
    else              return r->set(merge(l,r->l),r->r);
}

pair<np,np> split(np n,int x){ 
    if(!n) return {n,n};
    push(n);
    np l,r;
    if(n->money < x){
        tie(l,r) = split(n->r,x);
        return {n->set(n->l,l),r};
    }
    else{
        tie(l,r) = split(n->l,x);
        return {l,n->set(r,n->r)};
    }
}

np ins(np n, np x){
    if(!n) return x;
    np l,r;
    tie(l,r) = split(n,x->money);
    return merge(l,merge(x,r));
}

void get(np n,vector<np>& v){
    if(!n) return;
    push(n);
    get(n->l,v);
    v.push_back(n);
    get(n->r,v);
}
void buy(np n,int x){
    if(!n) return;
    n->money -=x;
    n->_money-=x;
    n->tshirt++;
    n->_tshirt++;
}


struct data{
    int c,q;
    bool operator<(data d){return (q==d.q) ? c<d.c : q>d.q;}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x;
    cin>>n;
    vector<data> d(n);
    rep(i,0,n) cin>>d[i].c>>d[i].q;
    sort(d.begin(),d.end());
    cin>>k;
    np rt=0;
    rep(i,0,k){
        cin>>x;
        rt = ins(rt,new node(x,i));
    }
    for(data& t:d){
        vector<np> v;
        np l,m,r;
        tie(l,m) = split(rt,t.c);
        buy(m,t.c);
        tie(m,r) = split(m,2*t.c);
        get(m,v);
        for(np& x:v) {
            x->l = x->r = 0;
            l = ins(l,x);
        }
        rt = merge(l,r);
        //get(rt,v);
        //for(np x:v) {
            //cout<<x->money<<" "<<x->tshirt<<" "<<x->id<<endl;
        //}
        //cout<<endl;
    }
    vector<int> ans(k);
    vector<np> v;
    get(rt,v);
    for(np x:v) {
        ans[x->id] = x->tshirt;
    }
    rep(i,0,k)cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}