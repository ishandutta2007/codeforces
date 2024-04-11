#include <stdio.h>
#define N 1000010
using namespace std;
int n,l,t,x[N],ll,rr,mid,tt;
long long ans=0;
bool ok(int i,int u){
    if (!u)return true;
    long long d1=u/(n-1);
    if (u%(n-1)==0)d1--;
    int t=u-d1*(n-1);
    d1*=l;
    if (t<=i)
        d1+=x[i]-x[i-t];
    else d1+=x[i]+l-x[n-(t-i)];
    return d1<=2*tt;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&l,&tt);
    if (n==1){
        puts("0");
        return 0;
    }
    for (int i=0;i<n;i++){
        char ch=getchar();
        while ((ch<'0')||(ch>'9'))ch=getchar();
        int u=0;
        while ((ch>='0')&&(ch<='9')){
            u=u*10+ch-'0';
            ch=getchar();
        }
        x[i]=u;
    }
    for (int i=0;i<n;i++){
        ll=0;rr=2*tt;
        while (ll<rr-1){
            int mid=((long long)ll+rr)/2;
            if (ok(i,mid))
                ll=mid;
            else rr=mid;
        }
        if (ok(i,rr))ans+=rr;else ans+=ll;
    }
    printf("%.10lf\n",ans*1.0/4);
}