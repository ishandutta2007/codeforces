#include <stdio.h>
#include <iostream>
#define MAX(a,b) (a)>(b)?(a):(b)
#define C 100000000
using namespace std;
string s,p;
double ans,cr;
int n,m;
bool ok(int x){
    long long f0=0,f1=-1000000000000000000LL,cu=x*1ll*n;
    for (int i=0;i<n;i++){
        long long nf0=MAX(f0-x,f1),nf1=MAX(f1-x,f0);
        f0=nf0;f1=nf1;
        if (s[i]=='R')f0=f0+C;
        if (s[i]=='L')f1=f1+C;
    }
    f0=MAX(f0,f1-x);
    return f0>=cu;
}
void check(){
    n=s.size();
    if (n%2==0)m=2*(n+1);else m=2*n;
    cr=0;
    for (int i=0;i<n;i++)cr+=(s[i]!='X');
    cr/=m;
    ans=MAX(ans,cr*C);
    int ll=0,rr=C;
    while (ll<rr-1){
        int mid=(ll+rr)>>1;
        if (ok(mid))ll=mid;else rr=mid;
    }
    if (ok(rr))cr=(rr+.0);else cr=(ll+.0);
    ans=MAX(ans,cr);
}
int main(){
    //freopen("input.txt","r",stdin);
    char c;
    c=getchar();
    while ((c=='X')||(c=='L')||(c=='R')){
        s+=c;
        c=getchar();
    }
    for (int i=0;i<s.size();i++){
        if ((i>0)&&(s[i]==s[i-1])&&(s[i]!='X'))p+='X';
        p+=s[i];
    }
    s=p;
    if ((s[0]==s[s.size()-1])&&(s[0]!='X')){
        s=p+'X';check();
        s='X'+p;check();
    }else check();
    //cout<<ok(50000000)<<endl;
    printf("%.6lf\n",ans*1e-6);
}