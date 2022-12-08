
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
typedef long long ll;
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        int cnt = 0;
        while(n%2==0) n/=2,cnt++;
        while(n%3==0) n/=3,cnt+=2;
        while(n%5==0) n/=5,cnt+=3;
        if(n==1) cout<<cnt<<endl;
        else cout<<-1<<endl;
    }
}