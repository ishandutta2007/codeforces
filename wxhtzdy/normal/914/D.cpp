#include <bits/stdc++.h>
using namespace std;

const int N=500050;

int a[N],st[N*4];
void Build(int c,int ss,int se){
    if(ss==se){ st[c]=a[ss];return;}
    int mid=ss+se>>1;
    Build(c*2,ss,mid);
    Build(c*2+1,mid+1,se);
    st[c]=__gcd(st[c*2],st[c*2+1]);
}

void Set(int c,int ss,int se,int qi,int val){
    if(ss>se||se<qi||ss>qi) return;
    if(ss==se){ st[c]=val;return;}
    int mid=ss+se>>1;
    Set(c*2,ss,mid,qi,val);
    Set(c*2+1,mid+1,se,qi,val);
    st[c]=__gcd(st[c*2],st[c*2+1]);
}

int cnt;
void Walk(int c,int ss,int se,int qs,int qe,int val){
    if(ss>se||qs>se||qe<ss) return;
    if(st[c]%val==0||cnt>1) return;
    if(ss==se){ cnt++;return;}
    int mid=ss+se>>1;
    Walk(c*2,ss,mid,qs,qe,val);
    Walk(c*2+1,mid+1,se,qs,qe,val);
}

int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++) scanf("%i",&a[i]);
    Build(1,1,n);
    int q;scanf("%i",&q);
    while(q--){
        int type;scanf("%i",&type);
        if(type==1){
            int l,r,x;scanf("%i%i%i",&l,&r,&x);
            cnt=0;Walk(1,1,n,l,r,x);
            if(cnt<=1) printf("YES\n");
            else printf("NO\n");
        }else{
            int pos,val;scanf("%i%i",&pos,&val);
            Set(1,1,n,pos,val);
        }
    }
    return 0;
}