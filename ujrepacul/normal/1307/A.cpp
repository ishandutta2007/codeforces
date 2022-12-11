#include <iostream>

using namespace std;
int v[103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,d,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            while(v[i] && d>=i-1)
            {
                --v[i];
                ++cnt;
                d-=(i-1);
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}