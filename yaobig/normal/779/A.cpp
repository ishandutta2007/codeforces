#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 5
#define pb push_back
using namespace std;
int cnt[maxn+5][2],diff[maxn+5],n,ans;
int main()
{
    int i,x,mark=1;
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&x),cnt[x][0]++;
    rep(i,1,n) scanf("%d",&x),cnt[x][1]++;
    rep(i,1,5) diff[i]=cnt[i][0]-cnt[i][1];
    rep(i,1,5) if((diff[i]&1)==1) mark=0;
    rep(i,1,5) ans+=(diff[i]>0)?diff[i]/2:0;
    printf("%d\n",(mark==1)?ans:-1);
    return 0;
}