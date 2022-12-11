#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int MOD=1e9+7;


int n,a[N],p2[N];
int f[N];


int solve(){
    for(int i=N-1;i>=1;i--) {
        f[i]=p2[a[i]]-1;
        for(int j=i+i;j<N;j+=i) f[i]=(f[i]-f[j])%MOD;
    }
    return (f[1]+MOD)%MOD;
}
int main(){
    p2[0]=1;
    for(int i=1;i<N;i++) p2[i]=p2[i-1]*2%MOD;
    ///
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<N;i++)
        for(int j=i+i;j<N;j+=i) a[i]+=a[j];
    cout<<solve();
}