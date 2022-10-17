#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int a[1005],b[1005];
vector<pair<int,int>> v1,v2;
int main()
{
    int n,m;cin>>n>>m;
    forij
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a) v1.push_back({b,c});
        else v2.push_back({b,c});
    }
    for(auto p:v1) for(int i=p.first+1;i<=p.second;++i) b[i]=1;
    for(auto p:v2) {
        int ok = 0;
        for(int i=p.first+1;i<=p.second;++i){
            if(b[i]>0) continue;
            if(b[i]<0) {ok=1;break;}
            b[i]=-1;
            ok=1;
            break;
        }
        if(!ok) {cout<<"NO"<<endl;return 0;}
    }
    cout<<"YES"<<endl;
    a[0]=1001;
    forii if(b[i]>=0) a[i]=a[i-1];else a[i]=a[i-1]-1;
    forii cout<<a[i]<<" ";cout<<endl;
}