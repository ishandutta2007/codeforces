#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll inf = 1e18;
const int N = 20;
const int M = 1<<N;
int n,a[N],b[N];
char s[N];

int trans(char c){
    if(c>='a'&&c<='f') return c-'a'+10;
    return c-'0';
}
bool check(int *f){
    for(int i=0;i<n;i++) if(f[i]<-15||f[i]>15) return 1;
    return 0;
}
ll dp[M],su[M];

char tran(int x){
    if(x>=10) return 'a'+x-10;
    return '0'+x;
}
char d[N];
void output(ll x){
    for(int i=0;i<n;i++){
        d[i]=tran(x%16);
        x/=16;
    }
    for(int i=n-1;i>=0;i--) printf("%c",d[i]);
    puts("");
    return ;
}

int main(){
    scanf("%s",s);n=strlen(s);
    int sum=0;
    for(int i=0;i<n;i++) a[i]=trans(s[i]);
    for(int i=0;i<n;i++) sum+=a[i];
    for(int i=0;i<n/2;i++) swap(a[i],a[n-i-1]);
    if(sum%15!=0){printf("NO\n");return 0;}
    sum/=15;
    ll ans=inf;
    for(int ms=0;ms<(1<<(n-1));ms++){
        int bt=0;
        for(int i=0;i<n;i++) if((ms>>i)&1) bt++;
        if(bt!=sum) continue;
        for(int i=0;i<n;i++){
            if((ms>>i)&1){
                b[i]=16-a[i];
                if(i&&((ms>>(i-1))&1)) b[i]--;
            }
            else{
                b[i]=-a[i];
                if(i&&((ms>>(i-1))&1)) b[i]--;
            }
        }
        if(check(b)) continue;
        if(b[n-1]>0) continue;
        for(int i=0;i<(1<<n);i++) dp[i]=inf,su[i]=0;
        b[n-1]=0;
        for(int i=1;i<(1<<n);i++){
            for(int j=0;j<n;j++)
                if((i>>j)&1){
                    su[i]=su[i^(1<<j)]+b[j];
                    break;
                }
        }
        dp[1<<(n-1)]=0;
        for(int i=1;i<(1<<n);i++){
            for(int j=0;j<n;j++)
                if((i>>j)&1){
                    if(su[i]<0||su[i]>15) continue;
                    dp[i]=min(dp[i],dp[i^(1<<j)]+(su[i]<<(j<<2)));
                }
        }
        ans=min(ans,dp[(1<<n)-1]);
    }
    if(ans==inf) printf("NO\n");
    else output(ans);
    return 0;
}