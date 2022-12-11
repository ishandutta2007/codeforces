#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=1000000;
struct node{
    long double x,y;
    bool operator<(const node b)const{
        return x==b.x?y<b.y:x<b.x;
    }
    long double operator*(const node b)const{
        if(x==b.x)return y<b.y?LDBL_MAX:LDBL_MIN;
        return (b.y-y)/(b.x-x);
    }
};
struct hull{
    set<node>st;
    bool nes(node kk){
        if(st.size()<=1||st.count(kk))return 1;
        node now=*st.rbegin();
        if(now.x<=kk.x)return now.y<kk.y;
        node nx=*st.lower_bound(kk),pr=*(--st.lower_bound(kk));
        return pr*kk>kk*nx;
    }
    void ins(node kk){
        if(st.count(kk))return;
        if(!st.size())return st.insert(kk),void();
        while(st.lower_bound(kk)!=st.end()&&st.lower_bound(kk)!=--st.end()){
            if(kk*(*st.lower_bound(kk))<(*st.lower_bound(kk))*(*(++st.lower_bound(kk))))st.erase(st.lower_bound(kk));
            else break;
        }
        while((--st.lower_bound(kk))!=st.begin()){
            if((*(--(--st.lower_bound(kk))))*(*(--st.lower_bound(kk)))<(*(--st.lower_bound(kk)))*kk)st.erase(--st.lower_bound(kk));
            else break;
        }
        st.insert(kk);
    }
}ty;
int q;
long double m;
int main(){
    scanf("%d%Lf",&q,&m);
    int last=0;
    ty.ins({0.0l,0.0l});
    for(int i=1;i<=q;i++){
        int tp;
        scanf("%d",&tp);
        int x,y;
        scanf("%d%d",&x,&y);
        x=(x+last)%mod+1,y=(y+last)%mod+1;
        if(tp==1){
            if(ty.nes({y*1.0l,x*1.0l}))ty.ins({y*1.0l,x*1.0l});
        }
        else{
            if(!ty.nes({m/x,y*1.0l/x}))puts("YES"),last=i;
            else puts("NO");
        }
    }
    return  0;
}
/*
12 100
1 8 8
2 200 101
2 10 99
1 9 9
2 10 99
2 200 101
1 14 4
2 194 195
2 194 194
2 990 290
2 999991 11
2 999991 10
*/