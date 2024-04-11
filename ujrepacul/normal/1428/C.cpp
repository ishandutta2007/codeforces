#include <bits/stdc++.h>
using namespace std;
char v[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,s=0,k,n,m;
    cin>>t;
    while(t--)
    {
        cin>>v;
        n=strlen(v);
        int cntb=0,cnt=n;
        for(i=n-1;i>=0;--i)
        {
            if(v[i]=='B')
                ++cntb;
            else
            {
                if(cntb)
                {
                    --cntb;
                    cnt-=2;
                }
            }
        }
        cnt-=(cntb)/2*2;
        cout<<cnt<<'\n';
    }
    return 0;
}