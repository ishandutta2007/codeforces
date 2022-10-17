#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans[505];
int main()
{
    for(int i=1;i<=500;++i)
    {
        ans[i] = ans[i-1] + (i+1)*(i+2);
    }
    int n;
    cin>>n;
    cout<<ans[n-2]<<endl;
}