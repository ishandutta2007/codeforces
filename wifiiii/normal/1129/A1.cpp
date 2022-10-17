#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef pair<int,int> pii;
typedef long long ll;

int c[5005],d[5005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) d[i]=1e9;
    for(int i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        c[a]++;
        int k = b-a;
        if(k<0) k+=n;
        d[a] = min(d[a], k);
    }
    for(int i=1;i<=n;++i) if(d[i]==1e9) d[i]=0;
    for(int i=1;i<=n;++i)
    {
        int ans = 0;
        for(int j=1;j<=n;++j)
        {
            int k = j-i;
            if(k<0) k+=n;
            ans = max(ans,(c[j]-1)*n+k+d[j]);
        }
        cout << ans <<" ";
    }
}