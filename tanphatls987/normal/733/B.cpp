#include <bits/stdc++.h>

using namespace std;

const string wowel="AEIOUY";


const int N=1e5+10;

int n,a[2][N];
int pL[2][N],pR[2][N];

int solve(){
    int ans=abs(pL[0][n]-pL[1][n]),use=0;
    for(int i=1;i<=n;i++){
        int v0=pL[0][i-1]+pR[0][i+1]+a[1][i];
        int v1=pL[1][i-1]+pR[1][i+1]+a[0][i];
//        cout<<i<<" "<<v0<<" "<<v1<<'\n';
        int nans=abs(v0-v1);
        if (nans>ans){
            ans=nans;
            use=i;
        }
    }
    return use;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=1;j++) scanf("%d",a[j]+i);
    for(int j=0;j<=1;j++){
        for(int i=1;i<=n;i++) pL[j][i]=pL[j][i-1]+a[j][i];
        for(int i=n;i>=1;i--) pR[j][i]=pR[j][i+1]+a[j][i];
    }
    cout<<solve();
}