#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long n,m,i,j,mx1=0,mx2=0,s=0,cntm1=0,cnt1=0,cnt0=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        long long a;
        cin>>a;
        if(a==0)
            ++cnt0;
        else
        if(a<0)
        {
            s+=(-1)-a;
            ++cntm1;
        }
        else
        {
            s+=a-1;
            ++cnt1;
        }
    }
    if(cntm1%2==1)
    {
        if(cnt0)
        {
            s+=cnt0;
            cout<<s;
            return 0;
        }
        else
        {
            s+=2LL;
            cout<<s;
            return 0;
        }
    }
    s+=cnt0;
    cout<<s;
	return 0;
}