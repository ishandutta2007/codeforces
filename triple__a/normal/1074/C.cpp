#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=300007;
int n;
int x[maxn],y[maxn],a[6][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    int xmin=1e9,xmax=-1e9,ymin=1e9,ymax=-1e9;
    for (int i=1;i<=n;++i){
        cin>>x[i]>>y[i];
        xmin=min(x[i],xmin), xmax=max(x[i],xmax);
        ymin=min(y[i],ymin), ymax=max(y[i],ymax);
    }
    a[0][0]=2, a[0][1]=0, a[0][2]=-2;
    a[1][0]=2, a[1][1]=-2, a[1][2]=0;
    a[2][0]=0, a[2][1]=2, a[2][2]=-2;
    a[3][0]=0, a[3][1]=-2, a[3][2]=2;
    a[4][0]=-2, a[4][1]=2, a[4][2]=0;
    a[5][0]=-2, a[5][1]=0, a[5][2]=2;
    int ans=0;
    for (int i=0;i<6;++i){
        for (int j=0;j<6;++j){
            int mx1=-4e8,mx2=-4e8,mx3=-4e8;
            for (int k=1;k<=n;++k){
                mx1=max(a[i][0]*x[k]+a[j][0]*y[k],mx1);
                mx2=max(a[i][1]*x[k]+a[j][1]*y[k],mx2);
                mx3=max(a[i][2]*x[k]+a[j][2]*y[k],mx3);
            }
            ans=max(ans,mx1+mx2+mx3);
        }
    }
    cout<<ans<<" ";
    for (int i=1;i<n-2;++i) cout<<2*(xmax+ymax-xmin-ymin)<<" ";
    return 0;
}