#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int main()
{
    int n;
    cin>>n;
    if(n==1) {cout<<1<<endl;return 0;}
    n--;
    int ans=0;
    int t=1;
    while(t<=2*n-1) ans+=t,t+=2;
    while(t>=1) ans+=t,t-=2;
    cout<<ans<<endl;
}
//1
//1 3 1
//1 3 5 3 1