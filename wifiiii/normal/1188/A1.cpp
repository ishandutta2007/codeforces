#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)

int in[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        in[u]++,in[v]++;
    }
    forii if(in[i]==2) {cout<<"NO"<<endl;return 0;}
    cout<<"YES"<<endl;
}