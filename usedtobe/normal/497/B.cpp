#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define N 222222
#define mp make_pair
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int n,a[N],t0[N],t1[N],c1,c0,s0[N],s1[N];
pii ans[N];
int can(int i) {
    int j,p0,p1;p0=p1=j=0;
    while (j<n) {
        if (t0[s0[j]+i]<t1[s1[j]+i]) p0++,j=t0[s0[j]+i];
        else p1++,j=t1[s1[j]+i];
        if (j>n) return 0;
    }
    if (p0>p1) return p0;else return 0;
}
int main() {
    scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);
    memset(t0,0x3f,sizeof t0);
    memset(t1,0x3f,sizeof t1);
    rep(i,1,n){
        if (a[i]==a[n])t0[++c0]=i;
        else t1[++c1]=i;
        s0[i]=c0;s1[i]=c1;
    }
    int cnt=0;
    rep(i,1,n) {int k=can(i);if (k) ans[++cnt]=mp(k,i);}
    printf("%d\n",cnt);
    sort(ans+1,ans+cnt+1);
    rep(i,1,cnt)printf("%d %d\n",ans[i].X,ans[i].Y);
    return 0;
}