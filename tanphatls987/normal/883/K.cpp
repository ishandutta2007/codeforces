#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

#define X first
#define Y second


const int N=2e5+10;


int n;
ii a[N];
ii ra[N];
int ans[N];

ii cross(ii a,ii b){
    if (a>b) swap(a,b);
    return ii(b.X,min(a.Y,b.Y));
}
void solve(){
    ra[n]=ii(a[n].X,a[n].X+a[n].Y);
    for(int i=n-1;i>=1;i--) {
//        cout<<
        ra[i]=cross(ii(ra[i+1].X-1,ra[i+1].Y+1),ii(a[i].X,a[i].X+a[i].Y));
        if (ra[i].X>ra[i].Y){
            cout<<"-1";
            return;
        }
    }
    ans[1]=ra[1].Y;
    for(int i=2;i<=n;i++){
        ii cur=cross(ii(ans[i-1]-1,ans[i-1]+1),ra[i]);
        ans[i]=cur.Y;
    }
    long long sum=0;
    for(int i=1;i<=n;i++) sum+=ans[i]-a[i].X;
    cout<<sum<<'\n';
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].X,&a[i].Y);
    solve();
}