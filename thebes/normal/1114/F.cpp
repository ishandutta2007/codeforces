#include <bits/stdc++.h>
using namespace std;

const int MN = 4e5+5, mod = 1e9+7;
int n, q, i, j, x, y, w, c, inv[303], pr[303];
vector<int> p; bitset<70> msk[3*MN], lz[3*MN];
struct nd{unsigned long long f, s;}st[3*MN];

long long qpow(int b,int exp){
    if(exp<=0) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}
inline void push_down(int i,int s,int e){
    if(st[i].s==1) return;
    st[i].f = (1LL*st[i].f*qpow(st[i].s,e-s+1))%mod;
    if(s!=e){
        st[2*i].s=(1LL*st[2*i].s*st[i].s)%mod;
        st[2*i+1].s=(1LL*st[2*i+1].s*st[i].s)%mod;
    }
    st[i].s = 1;
}
void upd(int i,int s,int e,int ss,int se,int v){
    push_down(i,s,e);
    if(s>=ss&&e<=se){
        st[i].s = v;
        push_down(i,s,e);
    }
    else{
        if((s+e)/2<ss){
            upd(2*i+1,(s+e)/2+1,e,ss,se,v);
            push_down(2*i,s,(s+e)/2);
        }
        else if((s+e)/2>=se){
            upd(2*i,s,(s+e)/2,ss,se,v);
            push_down(2*i+1,(s+e)/2+1,e);
        }
        else{
            upd(2*i,s,(s+e)/2,ss,se,v);
            upd(2*i+1,(s+e)/2+1,e,ss,se,v);
        }
        st[i].f=1LL*st[2*i].f*st[2*i+1].f%mod;
    }
}
int qu(int i,int s,int e,int ss,int se){
    push_down(i,s,e);
    if(s>=ss&&e<=se) return st[i].f;
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return 1LL*qu(2*i+1,(s+e)/2+1,e,ss,se)*qu(2*i,s,(s+e)/2,ss,se)%mod;
}
inline void push_down2(int i,int s,int e){
    if(!lz[i].count()) return;
    msk[i] |= lz[i];
    if(s != e){
        lz[2*i] |= lz[i];
        lz[2*i+1] |= lz[i];
    }
    lz[i].reset();
}
void upd2(int i,int s,int e,int ss,int se,int id){
    push_down2(i,s,e);
    if(s>=ss&&e<=se){lz[i][id]=1; push_down2(i,s,e);}
    else{
        if((s+e)/2<ss) upd2(2*i+1,(s+e)/2+1,e,ss,se,id),push_down2(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd2(2*i,s,(s+e)/2,ss,se,id),push_down2(2*i+1,(s+e)/2+1,e);
        else upd2(2*i+1,(s+e)/2+1,e,ss,se,id),upd2(2*i,s,(s+e)/2,ss,se,id);
        msk[i] = msk[2*i]|msk[2*i+1];
    }
}
bitset<70> qu2(int i,int s,int e,int ss,int se){
    push_down2(i,s,e);
    if(s>=ss&&e<=se) return msk[i];
    else{
        if((s+e)/2<ss) return qu2(2*i+1,(s+e)/2+1,e,ss,se);
        else if((s+e)/2>=se) return qu2(2*i,s,(s+e)/2,ss,se);
        else return qu2(2*i+1,(s+e)/2+1,e,ss,se)|qu2(2*i,s,(s+e)/2,ss,se);
    }
}
string s;
int main(){
    for(i=0;i<3*MN;i++) st[i].f=st[i].s=1;
    for(i=2;i<=300;i++){
        if(pr[i]) continue;
        p.push_back(i);
        for(j=i*i;j<=300;j+=i)
            pr[j] = 1;
    }
    for(scanf("%d%d",&n,&q),i=1;i<=n;i++){
        scanf("%d",&x);
        upd(1,1,n,i,i,x);
        for(j=0;j<p.size();j++){
            if(x%p[j]==0){
                c=0;
                while(x%p[j]==0){
                    c ++;
                    x /= p[j];
                }
                upd2(1,1,n,i,i,j);
            }
        }
    }
    for(i=1;i<=300;i++) inv[i]=qpow(i,mod-2);
    for(;q;q--){
        cin >> s;
        if(s[0]=='T'){
            scanf("%d%d",&x,&y);
            int r = qu(1,1,n,x,y);
            bitset<70> m = qu2(1,1,n,x,y);
            for(j=0;j<p.size();j++){
                if(m[j]){
                    r = (1LL*r*inv[p[j]])%mod;
                    r = (1LL*r*(p[j]-1))%mod;
                }
            }
            printf("%d\n",r);
        }
        else{
            scanf("%d%d%d",&x,&y,&w);
            upd(1,1,n,x,y,w);
            for(j=0;j<p.size();j++){
                if(w%p[j]==0){
                    while(w%p[j]==0) w/=p[j];
                    upd2(1,1,n,x,y,j);
                }
            }
        }
    }
    return 0;
}