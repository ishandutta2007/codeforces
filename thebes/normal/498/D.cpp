#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5,C=61;
struct nd{int f, s;}st[3*N][C];
int n, q, i, arr[N], x, y; char c;
void build(int i,int s,int e){
    if(s != e){
        build(2*i,s,(s+e)/2);
        build(2*i+1,(s+e)/2+1,e);
        for(int t=0;t<60;t++){
            st[i][t].f=st[2*i][t].f+st[2*i+1][(t+st[2*i][t].f)%60].f;
            st[i][t].s=st[2*i+1][t].s+st[2*i][(t+st[2*i+1][t].s)%60].s;
        }
    }
    else{
        for(int t=0;t<60;t++)
            st[i][t].f=st[i][t].s=1+(!(t%arr[s]));
    }
}
void upd(int i,int s,int e,int ind){
    if(s != e){
        if((s+e)/2<ind) upd(2*i+1,(s+e)/2+1,e,ind);
        else upd(2*i,s,(s+e)/2,ind);
        for(int t=0;t<60;t++){
            st[i][t].f=st[2*i][t].f+st[2*i+1][(t+st[2*i][t].f)%60].f;
            st[i][t].s=st[2*i+1][t].s+st[2*i][(t+st[2*i+1][t].s)%60].s;
        }
    }
    else{
        for(int t=0;t<60;t++)
            st[i][t].f=st[i][t].s=1+(!(t%arr[s]));
    }
}
int qu(int i,int s,int e,int ss,int se,int f,int t){
    if(s>=ss&&e<=se) return f? st[i][t].f:st[i][t].s;
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se,f,t);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se,f,t);
    else{
        int dt=(f)?qu(2*i,s,(s+e)/2,ss,se,f,t):qu(2*i+1,(s+e)/2+1,e,ss,se,f,t);
        return dt+(f?qu(2*i+1,(s+e)/2+1,e,ss,se,f,(t+dt)%60):qu(2*i,s,(s+e)/2,ss,se,f,(t+dt)%60));
    }
}
int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build(1, 1, n);
    for(scanf("%d",&q);q;q--){
        scanf(" %c%d%d",&c,&x,&y);
        if(c == 'C'){
            arr[x] = y;
            upd(1,1,n,x);
        }
        else{
            printf("%d\n",qu(1,1,n,x,y-1,y>=x,0));
        }
    }
    return 0;
}