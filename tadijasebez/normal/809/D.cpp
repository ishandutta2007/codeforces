//otrove! moj otrove!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
int ri(){int x;scanf("%i",&x);return x;}
const int N=300050;
int ls[N],rs[N],tsz,root,pri[N],lzy[N],val[N];
int nnd(int x){tsz++;pri[tsz]=rand();val[tsz]=x;return tsz;}
void upd(int c,int x){if(c)val[c]+=x,lzy[c]+=x;}
void push(int c){if(c)upd(ls[c],lzy[c]),upd(rs[c],lzy[c]),lzy[c]=0;}
void mrg(int &c,int a,int b){
    if(!a || !b){c=a^b;return;}
    if(pri[a]>pri[b])push(a),c=a,mrg(rs[c],rs[a],b);
    else push(b),c=b,mrg(ls[c],a,ls[b]);
}
void spl(int c,int &a,int &b,int k){
    if(!c){a=b=0;return;}
    push(c);
    if(val[c]<=k)a=c,spl(rs[c],rs[a],b,k);
    else b=c,spl(ls[c],a,ls[b],k);
}
void del(int &c){push(c);if(ls[c])del(ls[c]);else c=rs[c];}
int main(){
    int q=ri(),ans=0;
    while(q--){
        int l=ri(),r=ri();
        int a,b,c;
        spl(root,a,b,l-1);
        spl(b,b,c,r-1);
        upd(b,1);
        if(!c)ans++;
        else del(c);
        mrg(root,a,nnd(l));
        mrg(root,root,b);
        mrg(root,root,c);
    }
    printf("%i\n",ans);
    return 0;
}