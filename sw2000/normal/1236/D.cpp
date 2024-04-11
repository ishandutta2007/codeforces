#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;

vector<ll>nn[maxn],mm[maxn];

int main()
{
//    freopen("in.txt","r",stdin);
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    ll ma1=m+1,ma2=n+1,mi1=0,mi2=1;
    int boa[10][10]={0};
    for(int i=0;i<k;i++)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        boa[a][b]=1;
        nn[a].push_back(b);
        mm[b].push_back(a);
    }

    int op=1;
    ll sum=0,x=1,y=0;
    while(1)
    {
        if(op==1)
        {
            for(int i=0;i<nn[x].size();i++)
            {
                if(nn[x][i]>y)
                    ma1=min(ma1,nn[x][i]);
            }
            if(ma1-y==1)break;
            sum+=ma1-y-1;
            y=--ma1;
        }
        else if(op==2)
        {
            for(int i=0;i<mm[y].size();i++)
            {
                if(mm[y][i]>x)
                    ma2=min(ma2,mm[y][i]);
            }
            if(ma2-x==1)break;
            sum+=ma2-x-1;
            x=--ma2;
        }
        else if(op==3)
        {
            for(int i=0;i<nn[x].size();i++)
            {
                if(nn[x][i]<y)
                    mi1=max(mi1,nn[x][i]);
            }
            if(y-mi1==1)break;
            sum+=y-mi1-1;
            y=++mi1;
        }
        else if(op==4)
        {
            for(int i=0;i<mm[y].size();i++)
            {
                if(mm[y][i]<x)
                    mi2=max(mi2,mm[y][i]);
            }
            if(x-mi2==1)break;
            sum+=x-mi2-1;
            x=++mi2;
        }
        op++;
        if(op>4)op-=4;
//        cout<<x<<' '<<y<<' '<<sum<<endl;
//        cout<<ma1<<' '<<ma2<<' '<<mi1<<' '<<mi2<<endl;
//        if(op==4)break;
    }
    if(sum+k==n*m)puts("Yes");
    else puts("No");
    return 0;
}