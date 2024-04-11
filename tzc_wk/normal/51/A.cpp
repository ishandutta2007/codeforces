#include <bits/stdc++.h>
using namespace std;
const int BEGIN=11111111;
const int END=BEGIN*6;
const int ADD=1000;
const int MAXN=END+ADD;
bool t[MAXN];
int s[4];
int main()
{
    int n,u,i,x,y,tem,ans;
    char r[5];
    cin>>n;
    for(i=BEGIN;i<=END; i++)
        t[i]=0;
    for(u=1; u<=n; u++)
    {
        cin>>x>>y;
        if(u!=n) cin>>r;
        s[0]=x;
        s[1]=x%10*10+y%10;
        s[2]=y%10*10+y/10;
        s[3]=y/10*10+x/10;
        sort(s,s+4);
        tem=s[0]*1000000+s[1]*10000+s[2]*100+s[3];
        t[tem]=1;
    }
    ans=0;
    for(i=BEGIN;i<=END;i++)
        if(t[i]) ans++;
    cout<<ans;
    return 0;
}