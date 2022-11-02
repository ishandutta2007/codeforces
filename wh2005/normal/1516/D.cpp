#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,m,a[N],f[N][21],c[N];
int pr[N];
vector<int >fac[N];
void init(){
    int V=1e5;
    for(int i=2;i<=V;i++){
        if(!pr[i]){
            for(int j=i;j<=V;j+=i){
                pr[j]=1;fac[j].push_back(i);
            }
        }
    }
    return ;
}
bool check(int x){
    x=a[x];
    for(int i=0;i<fac[x].size();i++) if(c[fac[x][i]]) return 0;
    for(int i=0;i<fac[x].size();i++) c[fac[x][i]]++;
    return 1;
}
void remove(int x){
    x=a[x];
    for(int i=0;i<fac[x].size();i++) c[fac[x][i]]--;
    return ;
}

int main(){
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int r=0;
    for(int i=n+1;i<=n+10;i++)
        for(int j=0;j<=20;j++) f[i][j]=n+2;
    for(int l=1;l<=n;l++){
        while(r+1<=n&&check(r+1)) ++r;f[l][0]=r+1;
        remove(l);
    }
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
    while(m--){
        int l,r,ans=0;scanf("%d%d",&l,&r);
        for(int j=20;j>=0;j--)
            if(f[l][j]&&f[l][j]-1<=r){
                l=f[l][j];ans+=(1<<j);
            }
        printf("%d\n",ans+(l<=r));
    }
    return 0;
}