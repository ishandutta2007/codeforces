#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[2][N],b[2][N];
int calc(int &x,int &y){
    int res=min(x,y);
    x-=res,y-=res;
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<2;i++)for(int o=1;o<=n;o++)scanf("%d",&a[i][o]);
    for(int i=0;i<2;i++)for(int o=1;o<=n;o++)scanf("%d",&b[i][o]);
    long long ans=0,s1=0,s2=0;
    for(int i=1;i<=n;i++){
        s1+=a[0][i]+a[1][i];
        s2+=b[0][i]+b[1][i];
        ans+=abs(s1-s2);
    }
    if(s1!=s2)return puts("-1"),0;
    int s11=0,s12=0,s21=0,s22=0;
    for(int i=1;i<=n;i++){
        s11+=a[0][i];
        s12+=a[1][i];
        s21+=b[0][i];
        s22+=b[1][i];
        calc(s11,s21);
        calc(s12,s22);
        ans+=calc(s11,s22);
        ans+=calc(s12,s21);
        // cout<<i<<' '<<ans<<endl;
    }
    printf("%lld",ans);
    return  0;
}