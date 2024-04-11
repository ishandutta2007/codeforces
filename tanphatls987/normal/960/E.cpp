#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;
const int MOD=1e9+7;

int n;
int w[N];
long long way[N][2],f[N][2];

vector <int> v[N];

int q[N],pa[N];

void BFS(){
        int top=1,bot=1;
        q[1]=1;
        while (top<=bot){
                int x=q[top++];
                for(auto y:v[x]) if (y!=pa[x]){
                        pa[y]=x;
                        q[++bot]=y;
                }
        }
}

int main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<n;i++){
                int x,y;
                cin>>x>>y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        BFS();
        long long ans=0;
        for(int i=n;i>=1;i--){
                int x=q[i];
                way[x][0]=1;
                f[x][0]=w[x];
                ans=(ans+w[x])%MOD;
                for(auto y:v[x]) if (y!=pa[x]){
                        for(int i=0;i<=1;i++)
                                for(int j=0;j<=1;j++){
                                        int sign=(i==j)?-1:1;
                                        ///from x->y
                                        ans=(ans+way[y][j]*f[x][i]+sign*way[x][i]*f[y][j])%MOD;
                                        ///from y->x
                                        
                                        ans=(ans+sign*way[y][j]*f[x][i]+way[x][i]*f[y][j])%MOD;
                                }
                        for(int i=0;i<=1;i++){
                                int sign=i?1:-1;
                                f[x][i^1]=(f[x][i^1]+sign*way[y][i]*w[x]+f[y][i])%MOD;
                                way[x][i^1]=(way[x][i^1]+way[y][i])%MOD;
                        }
                }
        }
        cout<<(ans+MOD)%MOD;
}