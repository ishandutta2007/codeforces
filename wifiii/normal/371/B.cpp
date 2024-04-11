#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)


int c[4],d[4],e[4];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b;
    cin>>a>>b;
    if(a==b) {cout<<0<<endl;return 0;}
    int xa=a,xb=b;
    while(xa%2==0) xa/=2,c[1]++;
    while(xa%3==0) xa/=3,c[2]++;
    while(xa%5==0) xa/=5,c[3]++;
    swap(xa,xb);
    while(xa%2==0) xa/=2,d[1]++;
    while(xa%3==0) xa/=3,d[2]++;
    while(xa%5==0) xa/=5,d[3]++;
    if(xa!=xb) {cout<<-1<<endl;return 0;}
    a/=xa,b/=xb;
    int ans=0;
    //for(int i=1;i<=3;++i) cout<<c[i]<<" ";cout<<endl;
    //for(int i=1;i<=3;++i) cout<<d[i]<<" ";cout<<endl;
    for(int i=1;i<=3;++i)
    {
        ans += abs(c[i]-d[i]);
    }
    cout<<ans<<endl;
}