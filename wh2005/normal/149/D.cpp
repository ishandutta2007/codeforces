#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const int N = 709;
int n,lst[N],st[N],top;ll f[N][3][N][3];
char s[N];

int main(){
    scanf("%s",s);n=strlen(s);
    for(int i=n;i>=1;i--) s[i]=s[i-1];
    memset(f,0,sizeof(f));
    memset(lst,0,sizeof(lst));
    for(int i=1;i<=n;i++){
        if(s[i]=='(') st[++top]=i;
        else lst[st[top]]=i,top--;
    }
    for(int i=1;i<n;i++)
        if(s[i]=='('&&s[i+1]==')'){
            f[i][1][i+1][0]=1;
            f[i][2][i+1][0]=1;
            f[i][0][i+1][1]=1;
            f[i][0][i+1][2]=1;
        }
    for(int len=3;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            ll sum1=(f[i+1][0][j-1][0]+f[i+1][0][j-1][1]+f[i+1][0][j-1][2])%mod;
            ll sum2=(f[i+1][1][j-1][0]+f[i+1][1][j-1][1]+f[i+1][1][j-1][2])%mod;
            ll sum3=(f[i+1][2][j-1][0]+f[i+1][2][j-1][1]+f[i+1][2][j-1][2])%mod;

            ll sum4=(f[i+1][0][j-1][0]+f[i+1][1][j-1][0]+f[i+1][2][j-1][0])%mod;
            ll sum5=(f[i+1][0][j-1][1]+f[i+1][1][j-1][1]+f[i+1][2][j-1][1])%mod;
            ll sum6=(f[i+1][0][j-1][2]+f[i+1][1][j-1][2]+f[i+1][2][j-1][2])%mod;

            if(s[i]=='('&&s[j]==')'){
                (f[i][1][j][0]+=sum3+sum1)%mod;
                (f[i][2][j][0]+=sum2+sum1)%mod;
                (f[i][0][j][1]+=sum4+sum6)%mod;
                (f[i][0][j][2]+=sum5+sum4)%mod;
            }
            if(!lst[i]||lst[i]>=j) continue;
            int k=lst[i];
            for(int c1=0;c1<=2;c1++)
                for(int c2=0;c2<=2;c2++){
                    if(c1==c2&&c2!=0) continue;
                    (f[i][0][j][0]+=f[i][0][k][c1]*f[k+1][c2][j][0]%mod)%=mod;
                    (f[i][0][j][1]+=f[i][0][k][c1]*f[k+1][c2][j][1]%mod)%=mod;
                    (f[i][0][j][2]+=f[i][0][k][c1]*f[k+1][c2][j][2]%mod)%=mod;

                    (f[i][1][j][0]+=f[i][1][k][c1]*f[k+1][c2][j][0])%=mod;
                    (f[i][1][j][1]+=f[i][1][k][c1]*f[k+1][c2][j][1])%=mod;
                    (f[i][1][j][2]+=f[i][1][k][c1]*f[k+1][c2][j][2])%=mod;
                    
                    (f[i][2][j][0]+=f[i][2][k][c1]*f[k+1][c2][j][0])%=mod;
                    (f[i][2][j][1]+=f[i][2][k][c1]*f[k+1][c2][j][1])%=mod;
                    (f[i][2][j][2]+=f[i][2][k][c1]*f[k+1][c2][j][2])%=mod;
                    // if(i==1&&j==n) printf("[%d , %d] = [%d , %d] mer [%d , %d]\n",i,j,i,k,k+1,j);
                }
        }
    }
    ll ans=0;
    (ans+=f[1][0][n][0])%=mod;
    (ans+=f[1][0][n][1])%=mod;
    (ans+=f[1][0][n][2])%=mod;
    (ans+=f[1][1][n][0])%=mod;
    (ans+=f[1][1][n][1])%=mod;
    (ans+=f[1][1][n][2])%=mod;
    (ans+=f[1][2][n][0])%=mod;
    (ans+=f[1][2][n][1])%=mod;
    (ans+=f[1][2][n][2])%=mod;
    printf("%lld\n",ans);
    return 0;
}