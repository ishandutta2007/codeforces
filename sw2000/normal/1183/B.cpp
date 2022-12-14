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
        int n,mi=inf,ma=-1,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ma=max(a,ma);
            mi=min(a,mi);
        }
        if(ma-mi>k*2)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<mi+k<<endl;
        }
    }
    return 0;
}