#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=32;i++)
    {
        n-=k;
        if(n<=0)break;
        int cnt=0,tmp=n;
        while(tmp)
        {
            if(tmp&1)cnt++;
            tmp>>=1;
        }
        if(i>=cnt&&i<=n)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;

    return 0;
}