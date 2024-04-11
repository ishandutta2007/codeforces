#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c;
ll run(int st)
{
    ll A=a, B=b, C=c;
    for(int i=st;i<=7;i++)
    {
        if(i==1 || i==4 || i==7)
        {
            if(A>0) A--;
            else return i-st;
        }
        else if(i==2 || i==6)
        {
            if(B>0) B--;
            else return i-st;
        }
        else if(i==3 || i==5)
        {
            if(C>0) C--;
            else return i-st;
        }
    }
    ll ans=7-st+1;
    ll num=min(min(A/3,B/2),C/2);
    ans+=num*7;
    A-=3*num, B-=2*num, C-=2*num;
    for(int i=1;;i++)
    {
        if(i==1 || i==4 || i==7)
        {
            if(A>0) A--;
            else return ans+i-1;
        }
        else if(i==2 || i==6)
        {
            if(B>0) B--;
            else return ans+i-1;
        }
        else if(i==3 || i==5)
        {
            if(C>0) C--;
            else return ans+i-1;
        }
    }
}
int main()
{
    cin>>a>>b>>c;
    ll ans=0;
    for(int st=1;st<=7;st++)
    {
        ll res=run(st);
        //printf("%d: %I64d\n",st,res);
        ans=max(ans,res);
    }
    cout<<ans<<endl;
}