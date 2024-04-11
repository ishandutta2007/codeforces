#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
char s[N];
int main(){
    int x1,y1,x2,y2;scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
    int n;scanf("%i",&n);
    scanf("%s",s+1);
    int a[n+1],b[n+1];
    a[0]=0,b[0]=0;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1],b[i]=b[i-1];
        if(s[i]=='R')a[i]++;
        if(s[i]=='L')a[i]--;
        if(s[i]=='U')b[i]++;
        if(s[i]=='D')b[i]--;
        //printf("%i %i\n",a[i],b[i]);
    }
    ll bot=0,top=1e16,ans=1e16;
    while(bot<=top){
        ll mid=bot+top>>1;
        ll x=x1+a[n]*(mid/n)+a[mid%n],y=y1+b[n]*(mid/n)+b[mid%n];
        ll dist=abs(x-x2)+abs(y-y2);
        if(dist<=mid)ans=mid,top=mid-1;
        else bot=mid+1;
    }
    if(ans==1e16)printf("-1");
    else printf("%lld",ans);
    return 0;
}