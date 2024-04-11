#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;
const int M=5e3+10;
const int inf=1e9+10;

int n,k;
int f[2][M];

int a[N],mark[N],p[N];

bool comp(int x,int y){
        return a[x+1]-a[x]<a[y+1]-a[y];
}
int solve(){
        for(int i=0;i<=1;i++) fill(f[i],f[i]+M,inf);
        f[0][0]=0;
        for(int i=2;i<=n;i++){
                for(int j=k;j>=0;j--) {
                        f[0][j]=min(f[0][j],f[1][j]);
                        f[1][j]=f[0][j-1]+a[i]-a[i-1];
                }
        }
        return min(f[0][k],f[1][k]);
}
int main(){
        cin>>k>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        if (n>10010){
                for(int i=1;i<n;i++) p[i]=i;
                sort(p+1,p+n,comp);
                for(int i=1;i<=10010;i++) mark[p[i]]=mark[p[i]+1]=1;
                int n1=n;
                n=0;
                for(int i=1;i<=n1;i++) if (mark[i]) a[++n]=a[i];
        }
        cout<<solve();
}