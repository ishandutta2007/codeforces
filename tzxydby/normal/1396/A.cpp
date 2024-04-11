#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<1<<' '<<1<<endl<<-a[1]<<endl;
        cout<<1<<' '<<1<<endl<<1<<endl;
        cout<<1<<' '<<1<<endl<<-1<<endl;
        return 0;
    }
    cout<<1<<' '<<1<<endl<<-a[1]-n<<endl;
    cout<<2<<' '<<n<<endl;
    for(int i=2;i<=n;i++)
    {
        cout<<(n-1)*a[i]<<' ';
        a[i]+=(n-1)*a[i];
    }
    cout<<endl;
    cout<<1<<' '<<n<<endl;
    cout<<n<<' ';
    for(int i=2;i<=n;i++)
        cout<<-a[i]<<' ';
    cout<<endl;
    return 0;
}