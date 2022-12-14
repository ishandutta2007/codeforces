#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=3e3+10;
const ll mod=1e9+7;

int main()
{
//    freopen("in.txt","r",stdin);
    int cnt[4]={0},n,x,y;
    cin>>n>>x>>y;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a-=x;b-=y;
        if(a>0)cnt[0]++;
        if(a<0)cnt[1]++;
        if(b>0)cnt[2]++;
        if(b<0)cnt[3]++;
    }
    int ma=0,id;
    for(int i=0;i<4;i++)
    {
        if(cnt[i]>ma)
        {
            ma=cnt[i];
            id=i;
        }
    }
    cout<<cnt[id]<<endl;
    if(id==0)cout<<x+1<<' '<<y<<endl;
    else if(id==1)cout<<x-1<<' '<<y<<endl;
    else if(id==2)cout<<x<<' '<<y+1<<endl;
    else cout<<x<<' '<<y-1<<endl;


    return 0;
}