#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int a[maxn],b[maxn];
int n,t;
bool v[maxn][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;++i){
            for (int j=0;j<2;++j){
                v[i][j]=0;
            }
        }
        for (int i=1;i<=n;++i){
            cin>>a[i];
            if (a[i]==1||v[i-1][1]) v[i][1]=1;
            if (a[i]==-1||v[i-1][0]) v[i][0]=1;
        }
        for (int i=1;i<=n;++i){
            cin>>b[i];
        }
        bool fg=true;
        for (int i=n;i>0;--i){
            if (b[i]<a[i]&&!v[i-1][0]){
                fg=false;
            }
            if (b[i]>a[i]&&!v[i-1][1]) fg=false;
        }
        cout<<(fg?"YES":"NO")<<"\n";
    }
}