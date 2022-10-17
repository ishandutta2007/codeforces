
#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int a[105];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,k;
        cin>>n>>k;
        forii cin>>a[i];
        int m=1e9,M=-1;
        forii m=min(m,a[i]),M=max(M,a[i]);
        if(M-m>2*k) cout<<-1<<endl;
        else cout<<m+k<<endl;
    }
}