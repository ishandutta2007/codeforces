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
    int t;
    cin>>t;
    while(t--)
    {
        int n,s,t;
        cin>>n>>s>>t;
        int p=t+s-n;
        s-=p,t-=p;
        cout<<max(s,t)+1<<endl;
    }
}