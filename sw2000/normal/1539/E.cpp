#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<ll>vi;
const int N=2e5+10,M=26;
const int mod=1e7+7;
 
int n,m;
struct A{
    int k,l[2],r[2];
}a[N];
int l[N][2],r[N][2],nxt[N][2];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].k>>a[i].l[0]>>a[i].r[0]>>a[i].l[1]>>a[i].r[1];
    }
    memset(nxt,-1,sizeof(nxt));
    nxt[n+1][0]=nxt[n+1][1]=0;
    l[n+1][0]=l[n+1][1]=0;
    r[n+1][0]=r[n+1][1]=m;
 
    for(int i=n;i;i--){
        if(a[i].k>=a[i].l[0]&&a[i].k<=a[i].r[0]){
            if(~nxt[i+1][1]&&a[i].k>=l[i+1][1]&&a[i].k<=r[i+1][1]){
                nxt[i][0]=1;
                l[i][0]=a[i].l[1];
                r[i][0]=a[i].r[1];
            }
            else if(~nxt[i+1][0]){
                l[i][0]=max(a[i].l[1],l[i+1][0]);
                r[i][0]=min(a[i].r[1],r[i+1][0]);
                if(l[i][0]<=r[i][0])nxt[i][0]=0;
            }
        }
        if(a[i].k>=a[i].l[1]&&a[i].k<=a[i].r[1]){
            if(~nxt[i+1][0]&&a[i].k>=l[i+1][0]&&a[i].k<=r[i+1][0]){
                nxt[i][1]=0;
                l[i][1]=a[i].l[0];
                r[i][1]=a[i].r[0];
            }
            else if(~nxt[i+1][1]){
                l[i][1]=max(a[i].l[0],l[i+1][1]);
                r[i][1]=min(a[i].r[0],r[i+1][1]);
                if(l[i][1]<=r[i][1])nxt[i][1]=1;
            }
        }
    }
    if(~nxt[1][0]&&0>=l[1][0]&&0<=r[1][0]){
        int ans=0;
        cout<<"Yes\n";
        for(int i=1;i<=n;i++){
            cout<<ans<<' ';
            ans=nxt[i][ans];
        }
    }
    else if(~nxt[1][1]&&0>=l[1][1]&&0<=r[1][1]){
        int ans=1;
        cout<<"Yes\n";
        for(int i=1;i<=n;i++){
            cout<<ans<<' ';
            ans=nxt[i][ans];
        }
    }
    else cout<<"No";
}