#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int n;
string x,y;

bool f()
{
    if(x==y)return 1;
    int cnt=0;
    string a,b;
    for(int i=0;i<n;i++)
    {
        if(x[i]!=y[i])
        {
            cnt++;
            a+=x[i];
            b+=y[i];
        }
    }
    if(cnt!=2)return 0;
    if(a[0]==a[1]&&b[1]==b[0])return 1;
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>n>>x>>y;
        if(f())puts("yes");
        else puts("no");
    }
}