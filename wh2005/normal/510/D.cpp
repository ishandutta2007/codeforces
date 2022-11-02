#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 309;
const int M = 2e5+9;
int n,cnt;struct pp{ll cos;int x;}a[N];
map<int ,int >mp;
int gcd(int x,int y){if(!y) return x;return gcd(y,x%y);}
ll f[M];int p[M];
int main(){
    scanf("%d",&n);cnt=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i].x);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i].cos);
    memset(f,0x3f,sizeof(f));
    p[++cnt]=a[1].x,f[1]=a[1].cos;mp[a[1].x]=cnt;
    for(int i=2;i<=n;i++){
        int lst=cnt;
        for(int j=1;j<=lst;j++){
            int x=gcd(p[j],a[i].x);
            if(!mp[x]) mp[x]=++cnt,p[cnt]=x;
            f[mp[x]]=min(f[mp[x]],f[j]+a[i].cos);
        }
        if(!mp[a[i].x]) mp[a[i].x]=++cnt,p[cnt]=a[i].x;
        f[mp[a[i].x]]=min(f[mp[a[i].x]],a[i].cos);
    }
    if(!mp[1]) printf("-1\n");
    else printf("%lld\n",f[mp[1]]);
    return 0;
}
/*

gcd1
*/