#include <stdio.h>
#include <algorithm>
#define N 600500
using namespace std;
int r[N],s[N],e[N],x,y,q,u,v,n,m,w,t,o,l,k,p,j;
void upd(int x,int v){for(x;x<=n;x=(x|(x-1))+1)s[x]+=v;}
int sum(int x){int r=0;for(x;x;x&=x-1)r+=s[x];return r;}
void calc(int &a,int &b,int &c,int &d){
    a=((x<n)&&(r[x]>r[x+1]));
    b=((x>1)&&(r[x-1]>r[x]));
    c=((y<n)&&(r[y]>r[y+1]));
    d=((y>1)&&(r[y-1]>r[y]));
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&e[i]);
        r[e[i]]=i;
    }
    for (int i=1;i<n;i++)upd(i,r[i]>r[i+1]);
    scanf("%d",&m);
    for (int i=0;i<m;i++){
        scanf("%d%d%d",&q,&x,&y);
        if (q==1)
            printf("%d\n",1+sum(y-1)-sum(x-1));
        else{
            swap(e[x],e[y]);
            x=e[x];y=e[y];
            if (x>y)swap(x,y);
            calc(q,w,j,t);
            swap(r[x],r[y]);
            calc(o,p,l,k);
            upd(x,o-q);upd(y,l-j);
            if (x>1)upd(x-1,p-w);
            if ((y>1)&&(y-1!=x))upd(y-1,k-t);
        }
    }
}