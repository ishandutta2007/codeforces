#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const ll N=1000005,M=100005,MOD=1e9+7;
ll n,l,m;
ll mas[N],mas1[N],mas2[N];
ll a[200],b[200];
ll mat[105][105],mm[105][105],ma[105][105];
ll sac[105][105];
ll ans;
void mult (ll A[105][105], ll B[105][105]){
    for (ll i=0;i<m;i++)
        for (ll j=0;j<m;j++)
            sac[i][j]=0;
    for (ll i=0;i<m;i++)
        for (ll j=0;j<m;j++)
            for (ll l=0;l<m;l++)
                sac[i][l]=(sac[i][l]+A[i][j]*B[j][l])%MOD;
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            A[i][j]=sac[i][j];
}
void POWER (){
    if (l==0){
        for (int i=0;i<m;i++)
            for (int j=0;j<m;j++)
                mat[i][j]=0;
        for (int i=0;i<m;i++)
            mat[i][i]=1;
        return;
    }
    ll k=1;
    l--;
    for (ll i=0;i<m;i++)
        for (ll j=0;j<m;j++)
            ma[i][j]=mat[i][j],mm[i][j]=mat[i][j];
    while (k<=l){
        if (k&l){
            mult(ma,mm);
        }
        mult(mm,mm);
        k*=2;
    }
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            mat[i][j]=ma[i][j];
}
int main() {
    cin>>n>>l>>m;
    l--;
    l--;
    for (ll i=1;i<=n;i++){
        scanf("%d",&mas1[i]);
        mas1[i]%=m;
        a[mas1[i]]++;
    }
    for (ll i=1;i<=n;i++){
        scanf("%d",&mas[i]);
        for (ll j=0;j<m;j++)
            mat[j][(j+mas[i])%m]++;
    }
    for (ll i=1;i<=n;i++){
        scanf("%d",&mas2[i]);
        mas2[i]+=mas[i];
        mas2[i]%=m;
    }
    POWER();
    for (ll i=0;i<m;i++)
        for (ll j=0;j<m;j++)
            b[j]=(b[j]+a[i]*mat[i][j])%MOD;
    for (ll i=1;i<=n;i++){
        ans=(ans+b[(m-mas2[i])%m])%MOD;
    }
    cout<<ans<<endl;
    return 0;
}