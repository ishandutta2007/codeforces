#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=100+10;
const int inf=0x3f3f3f3f;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,a,b;
        cin>>n>>k>>a>>b;
        n--;
        if(n/b<k)
        {
            cout<<-1<<endl;
        }
        else
        {
            n-=b*k;
            if(n/(a-b)>k)cout<<k<<endl;
            else cout<<n/(a-b)<<endl;
        }
    }
    return 0;
}