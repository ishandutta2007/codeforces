#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;
const long long inf=1e16;
int n,a[N];

long long f[2][N][3];

template <class T>
bool minimize(T &x,T y){
        if (x>y) x=y;else return 0;
        return 1;
}
int comp(int x,int y){
        if (x==y) return 1;
        if (x<y) return 0;
        return 2;
}
int main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];

        for(int i=0;i<=(n+1)/2;i++) 
                for(int j=0;j<3;j++) f[1][i][j]=inf;
        f[1][0][2]=0;
        for(int i=1;i<n;i++){
                int cur=i%2,next=cur^1;
                for(int j=0;j<=(n+1)/2;j++)
                        for(int k=0;k<3;k++) f[next][j][k]=inf;
                for(int j=0;j<=(n+1)/2;j++){
                        int type=comp(a[i+1],min(a[i-1]-1,a[i]));
                        minimize(f[next][j][type],f[cur][j][0]);
                        minimize(f[next][j][2],f[cur][j][0]+max(min(a[i],a[i-1]-1)-a[i+1]+1,0));
                        ////
                        type=comp(a[i+1],a[i]);
                        minimize(f[next][j][type],f[cur][j][1]);
                        minimize(f[next][j][2],f[cur][j][1]+max(a[i]-a[i+1]+1,0));
                        ////

                        minimize(f[next][j+1][0],f[cur][j][2]+max(a[i+1]-a[i]+1,0));
                        minimize(f[next][j][2],f[cur][j][2]+max(a[i]-a[i+1]+1,0));
                        minimize(f[next][j][type],f[cur][j][2]);
                }
        }
        for(int i=1;i<=(n+1)/2;i++) cout<<min(min(f[n&1][i][0],f[n&1][i][1]),f[n&1][i-1][2])<<" ";
}