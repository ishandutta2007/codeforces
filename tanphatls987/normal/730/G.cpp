#include <bits/stdc++.h>

using namespace std;

const int inf=2e9;
const int N=5e2+10;

int n,a[N],dur[N];
int ans[N];

bool cross(int xa,int ya,int xb,int yb){
    if (xa>xb) {
        swap(xa,xb);
        swap(ya,yb);
    }
//    cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<'\n';
    return xb<=min(ya,yb);
}
bool check(int st,int per){
    int en=st+dur[per]-1;
    for(int i=1;i<per;i++) if (cross(ans[i],ans[i]+dur[i]-1,st,en)) return 0;
    return 1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>dur[i];
    ans[0]=1;
    for(int i=1;i<=n;i++){
        if (check(a[i],i)) ans[i]=a[i];
        else {
            ans[i]=inf;
            for(int j=0;j<i;j++) if (check(ans[j]+dur[j],i)){
//                cout<<ans[j]+dur[j]<<'\n';
                ans[i]=min(ans[i],ans[j]+dur[j]);
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d %d\n",ans[i],ans[i]+dur[i]-1);
}