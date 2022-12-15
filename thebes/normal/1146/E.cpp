#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5, MM=2e5+1, sh=1e5+1;
int st[10*MN], lz[10*MN], flag, n, q, i, arr[MN], x;
char ch;

void build(int i,int s,int e){
    if(s!=e){
        build(2*i,s,(s+e)/2);
        build(2*i+1,(s+e)/2+1,e);
    }
    else st[i]=1;
    lz[i]=-1;
}

inline void push_down(int i,int s,int e){
    if(lz[i]==-1) return;
    st[i]=lz[i];
    if(s!=e) lz[2*i]=lz[2*i+1]=lz[i];
    lz[i]=-1;
}

void upd(int i,int s,int e,int ss,int se,int val){
    push_down(i,s,e);
    if(s>=ss&&e<=se) lz[i]=val, push_down(i,s,e);
    else{
        if((s+e)/2<ss){
            upd(2*i+1,(s+e)/2+1,e,ss,se,val);
            push_down(2*i,s,(s+e)/2);
        }
        else if((s+e)/2>=se){
            upd(2*i,s,(s+e)/2,ss,se,val);
            push_down(2*i+1,(s+e)/2+1,e);
        }
        else{
            upd(2*i,s,(s+e)/2,ss,se,val);
            upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        }
    }
}

void ree(int l,int r,int val){
    if(l>r) return;
    if(!flag) upd(1,1,MM,l,r,val);
    else upd(1,1,MM,MM-r+1,MM-l+1,val);
}

int qu(int i,int s,int e,int idx){
    push_down(i,s,e);
    if(s==e) return st[i];
    else if((s+e)/2<idx) return qu(2*i+1,(s+e)/2+1,e,idx);
    else return qu(2*i,s,(s+e)/2,idx);
}

int argh(int idx){
    if(!flag) return qu(1,1,MM,idx);
    else return qu(1,1,MM,MM-idx+1);
}

int main(){
    build(1,1,MM);
    for(i=1;i<10*MN;i++) st[i]=1;
    argh(sh+1);
    for(scanf("%d%d",&n,&q),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=q;i++){
        scanf(" %c%d",&ch,&x);
        if(ch=='<'){
            if(0<x){
                flag = !flag;
                ree(1,sh-x,0);
                ree(x+sh,MM,1);
            }
            else{
                ree(1,sh+x-1,0);
                ree(-x+sh+1,MM,1);
            }
        }
        else{
            if(0>x){
                flag = !flag;
                ree(-x+sh,MM,0);
                ree(1,sh+x,1);
            }
            else{
                ree(x+sh+1,MM,0);
                ree(1,sh-x-1,1);
            }
        }
    }
    for(i=1;i<=n;i++){
        if(argh(arr[i]+sh)&&argh(-arr[i]+sh)) printf("%d ",!flag?arr[i]:-arr[i]);
        else if(argh(arr[i]+sh)) printf("%d ",arr[i]);
        else printf("%d ",-arr[i]);
    }
    printf("\n");
    return 0;
}