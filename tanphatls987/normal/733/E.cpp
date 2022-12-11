#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10;

int n,a[N];

ll fL[2][N],fR[2][N];
ll cL[2][N],cR[2][N];
string s;
void prepare(){
    cin>>n>>s;
    for(int i=1;i<=n;i++) a[i]=s[i-1]=='U';
    for(int j=0;j<=1;j++)
        for(int i=1;i<=n;i++){
            fL[j][i]=fL[j][i-1];
            cL[j][i]=cL[j][i-1];
            if (a[i]==j){
                fL[j][i]+=i;
                cL[j][i]++;
            }
        }
    for(int j=0;j<=1;j++)
        for(int i=n;i>=1;i--){
            fR[j][i]=fR[j][i+1];
            cR[j][i]=cR[j][i+1];
            if (a[i]==j){
                fR[j][i]+=n-i+1;
                cR[j][i]++;
            }
        }
}
void solve(){
    for(int i=1;i<=n;i++) if (a[i]==1){
        int p1=cL[1][i],p2=cR[0][i+1];
//        cout<<p1<<" "<<p2<<'\n';
        if (p1<=p2){
            int idx=lower_bound(cL[0]+1,cL[0]+n+1,cL[0][i-1]+p1)-cL[0];
            printf("%lld ",2*((fL[0][idx]-fL[0][i])-fL[1][i])+i);
        }else{
            int idx=upper_bound(cL[1]+1,cL[1]+n+1,p1-p2-1)-cL[1];
            printf("%lld ",2*(-(fL[1][i-1]-fL[1][idx-1])+(fL[0][n]-fL[0][i]))+(n-i+1));
        }
    }else{
        int p1=cR[0][i],p2=cL[1][i-1];
        if (p1<=p2){
            int idx=upper_bound(cL[1]+1,cL[1]+n+1,p2-p1)-cL[1];
            printf("%lld ",2*(-fR[0][i]+(fR[1][idx]-fR[1][i]))+(n-i+1));
        }else{
            int idx=lower_bound(cL[0]+1,cL[0]+n+1,cL[0][i]+p2)-cL[0];
            printf("%lld ",2*((fR[1][1]-fR[1][i])-(fR[0][i+1]-fR[0][idx+1]))+i);
        }
    }
}
int main(){
    prepare();
    solve();
}