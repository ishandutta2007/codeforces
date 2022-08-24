#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int C,a,b,c,d,D;
long long ans,x,y;
int exgcd(int k1,int k2){
    if (k2==0){
        x=1; y=0; return k1;
    }
    int d=exgcd(k2,k1%k2);
    long long tmp=x; x=y; y=tmp-y*(k1/k2); return d;
}
long long calc(int k){
    if (k%D) return 0;
    long long k1=1ll*k/D*x,k2=1ll*k/D*y,k3=a/D,k4=c/D;
    long long k5=k2/k3; k1+=k5*k4; k2-=k5*k3;
    while (k2>=k3){
        k1+=k4; k2-=k3;
    }
    while (k2<0){
        k1-=k4; k2+=k3;
    }
    if (k2<0||k3<0) return 0;
    return 1ll*k1*b+1ll*k2*d;
}
int main(){
    scanf("%d%d%d%d%d",&C,&b,&d,&a,&c);
    if (1ll*a*d>=1ll*b*c){
        swap(a,c); swap(b,d);
    }
    ans=0;
    if (c>=100000){
        for (int i=0;i*c<=C;i++) ans=max(ans,1ll*i*d+1ll*(C-i*c)/a*b);
        cout<<ans<<endl;
    } else {
        D=exgcd(a,c);
        for (int i=C;i>=max(0,C-c);i--) ans=max(ans,calc(i));
        cout<<ans<<endl;
    }
    return 0;
}