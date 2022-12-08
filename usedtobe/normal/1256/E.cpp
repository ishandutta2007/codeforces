#include<bits/stdc++.h>
using namespace std;
const int N=1111111;
int n,m,b[N];
struct S{
    int x,id;
    S(){}
};
S a[N];
long long f[N],mx=-1e9;
int pre[N];
bool cmp(S a,S b){
    return a.x<b.x;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i].x);
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    f[3]=a[3].x-a[1].x;
    pre[3]=0;
    int now=0;
    mx=-a[1].x;
    for(int i=4;i<=n;++i){
        f[i]=a[i].x-a[1].x;
        if (f[i]>mx+a[i].x) {
            pre[i]=now;
            f[i]=mx+a[i].x;
        }
        if(i-2>=3){
            // cout <<i  << " " << f[i-2]-a[i-1].x << " / " << mx << endl;
            if(f[i-2]-a[i-1].x<mx){
                mx=f[i-2]-a[i-1].x;
                now=i-2;
            }
        }
    }
    int cc=0;
    for (int i=n;i;i=pre[i]){
        ++cc;
        for(int j=pre[i]+1;j<=i;++j)b[a[j].id]=cc;
    }
    cout<<f[n]<<" "<<cc<<endl;
    for(int i=1;i<=n;++i){
        printf("%d ",b[i]);
    }
    puts("");

    return 0;
}