#include<bits/stdc++.h>
using namespace std;
#define vi vector<int >
int p;
vi a,xx,yy;

int ask(int x,int y){
    printf("0 %d %d\n",x,y);
    fflush(stdout);
    int t;scanf("%d",&t);
    return t;
}

void solve(int l,int r){
    if(l>r) return ;
    if(l==r){
        if(!ask(l,l)) a.push_back(l);
        return ;
    }
    int mid=(l+r)>>1;
    int res=ask(mid,mid);
    if(!res){a.push_back(mid);res=1;}
    solve(l,mid-res);
    solve(mid+res,r);
    return ;
}


int main(){
    int L=-1e8,R=1e8;
    for(;;L++){
        int res=ask(L,L);
        if(res){
            p=L;break;
        }
        else a.push_back(L);
    }
    solve(L,R);
    for(int i=0;i<a.size();i++){
        int x=a[i];
        if(!ask(x,p)) xx.push_back(x);
        if(!ask(p,x)) yy.push_back(x);
    }
    printf("1 %d %d\n",(int)xx.size(),(int)yy.size());
    fflush(stdout);
    for(int i=0;i<xx.size();i++){printf("%d ",xx[i]);fflush(stdout);}
    for(int i=0;i<yy.size();i++){printf("%d ",yy[i]);fflush(stdout);}
    return 0;
}