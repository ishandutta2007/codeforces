#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int a[100005];
int main()
{
    int n;
    cin>>n;
    forii cin>>a[i];
    forii if(a[i]>=0) a[i]=-a[i]-1;
    if(n%2)
    {
        int mi=-1,mx=1e9;
        forii if(a[i]<mx) mx=a[i],mi=i;
        a[mi]=-a[mi]-1;
    }
    forii cout<<a[i]<<" ";cout<<endl;
}