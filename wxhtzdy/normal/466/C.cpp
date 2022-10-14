#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,cnt[N],sm[N],a[N],s=0,cs=0,res=0;
int main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]),s+=a[i];
    if(s%3!=0){printf("0");return 0;}
    sm[n]=0;
    for(int i=n-1;i>=0;i--){
        cs+=a[i];
        if(cs==(s/3))cnt[i]=1;
        else cnt[i]=0;
        sm[i]=cnt[i];
        if(i<n-1)sm[i]+=sm[i+1];
    }
    cs=0;
    for(int i=0;i+2<n;i++){
        cs+=a[i];
        if(cs==s/3)res+=sm[i+2];
    }
    printf("%lld",res);
}