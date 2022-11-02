#include<bits/stdc++.h>
using namespace std;
#define db double
const db eps = 1e-8;
const int N = 2e3+9;
int n,A,B,cnta,cntb;
db a[N],b[N],c[N];
db check(db csa,db csb){
    cnta=0,cntb=0;db dp=0;
    for(int i=1;i<=n;i++){
        db tmp=0;int fla=0,flb=0;
        if(tmp+eps<a[i]-csa){tmp=a[i]-csa;fla=1;}
        if(tmp+eps<b[i]-csb){tmp=b[i]-csb;flb=1,fla=0;}
        if(tmp+eps<c[i]-csa-csb){
            tmp=c[i]-csa-csb;
            fla=1,flb=1;
        }
        dp+=tmp,cnta+=fla,cntb+=flb;
    }
    return dp;
}

int main(){
    scanf("%d%d%d",&n,&A,&B);
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lf",&b[i]);
    for(int i=1;i<=n;i++) c[i]=1.0-(1.0-a[i])*(1.0-b[i]);
    db la=0,ra=1,csa=0,csb=0,ans=0;
    while(la+eps<ra){
        db mida=(la+ra)/2.0;
        db lb=0,rb=1;
        while(lb+eps<rb){
            db midb=(lb+rb)/2.0;
            ans=check(mida,midb);
            csb=midb;
            if(cntb==B) break;
            if(cntb<=B) rb=midb;
            else lb=midb;
        }
        csa=mida;
        if(cnta==A) break;
        if(cnta<=A) ra=mida;
        else la=mida;
    }
    printf("%.8lf\n",ans+csa*A+csb*B);
    return 0;
}