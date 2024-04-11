#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=2e5+10;
const int MOD=1e9+9;



int n;
vector <int> v[N];
int pa[N];

int f[N][2];
vector <int> t[N][2];
int q[N];
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

void trace(int x,int label){
        int n1=v[x].size();
        
        for(int i=n1-1;i>=0;i--){
                int y=v[x][i];
                if (y==pa[x]) continue;
                int use=t[x][label][i];
                if (use==0) trace(y,use);
        }
        cout<<x<<" ";
        for(int i=n1-1;i>=0;i--){
                int y=v[x][i];
                if (y==pa[x]) continue;
                int use=t[x][label][i];
                if (use==1) trace(y,use);
        }
}


int tr[2][2][N];
int cf[2][2],tf[2][2];
void solve(){
        BFS();
        for(int j=n;j>=1;j--){
                int cur=q[j];
                memset(cf,0,sizeof(cf));
                cf[1][0]=cf[0][1]=1;
                int n1=v[cur].size();
                for(int i=0;i<n1;i++){
                        int y=v[cur][i];
                        if (y==pa[cur]) continue;
                        for(int k0=0;k0<=1;k0++)
                                for(int k1=0;k1<=1;k1++) tf[k0][k1]=cf[k0][k1];
                        memset(cf,0,sizeof(cf));
                        for(int k0=0;k0<=1;k0++)
                                for(int k1=0;k1<=1;k1++) if (tf[k0][k1]){
                                        for(int last=0;last<=1;last++) if (f[y][last]){
                                                cf[k0^last][k1]=1;
                                                tr[k0^last][k1][i]=last;
                                        }
                        }

                }
                for(int i=0;i<=1;i++){
                        f[cur][i]=cf[0][i];
                        int st=0;
                        t[cur][i].resize(n1);
                        for(int j=n1-1;j>=0;j--) {
                                int y=v[cur][j];
                                if (y==pa[cur]) continue;
                                t[cur][i][j]=tr[st][i][j];
                                st^=tr[st][i][j];
                        }
                }
        }

        if (f[1][1]){
                cout<<"YES\n";
                v[1].push_back(0);
                t[1][0].push_back(0);
                t[1][1].push_back(0);
                trace(1,1);
                return;
        }
        cout<<"NO";
}
int main(){
        cin>>n;
        if (n%2==0){
                cout<<"NO";
                return 0;
        }
        for(int i=1;i<=n;i++){
                int x;
                cin>>x;
                if (x!=0) {
                        v[x].push_back(i);
                        v[i].push_back(x);
                }
        }
        for(int i=1;i<=n;i++) 
                for(int j=0;j<=1;j++) t[i][j].resize(v[i].size());
        solve();
}