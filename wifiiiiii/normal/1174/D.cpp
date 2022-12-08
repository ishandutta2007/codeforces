
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int a[1000005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    if(x>=(1<<n))
    {
        int tot=(1<<n)-1;
        cout<<tot<<endl;
        int tmp=1;
        while(tmp<=(1<<n))
        {
            for(int i=tmp;i<=tot;i+=tmp)
            {
                a[i]=tmp;
            }
            tmp<<=1;
        }
        rep(i,tot) cout<<a[i]<<" ";
    }
    else
    {
        int tot=(1<<(n-1))-1;
        cout<<tot<<endl;
        int x2 = 1;
        while(x2<=x) x2<<=1;
        x2>>=1;
        int tmp1=1,tmp2=1;
        while(tmp1<=(1<<n))
        {
            if(tmp1==x2) tmp2<<=1;
            for(int i=tmp1;i<=tot;i+=tmp1)
            {
                a[i]=tmp2;
            }
            tmp1<<=1,tmp2<<=1;
        }
        rep(i,tot) cout<<a[i]<<" ";
    }
}