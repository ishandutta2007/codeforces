#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll b[maxn][maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&b[i][j]);
        }
    }

    b[0][0]=sqrt(b[0][1]*b[0][2]/b[1][2]);

    for(int i=1;i<n;i++)
    {
        b[i][i]=b[i-1][i]/b[i-1][i-1];
    }

    for(int i=0;i<n;i++)printf("%lld ",b[i][i]);
    return 0;
}