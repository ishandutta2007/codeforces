#include <bits/stdc++.h>

using namespace std;
#define int long long
int query(int x,int y)
{
    cout<<"SCAN "<<x<<' '<<y<<endl;
    int ans;cin>>ans;return ans;
}
int get(int x,int y)
{
    cout<<"DIG "<<x<<' '<<y<<endl;
    int ans;cin>>ans;return ans;
}
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        int ans1=query(1,1);int ans2=query(1,m);
        int sumx=((ans1+ans2)-(2*m-6))/2;int sumy=((ans1-ans2)+(2*m+2))/2;
        int ans3=query(sumx/2,1);ans3-=(sumy-2);int rax=ans3;
        int ans4=query(1,sumy/2);ans4-=(sumx-2);int ray=ans4;
        int x1=(sumx-rax)/2;int x2=(sumx+rax)/2;int y1=(sumy-ray)/2;int y2=(sumy+ray)/2;
        int o1=get(x1,y1);
        if(o1==0)
        {
            get(x2,y1);get(x1,y2);
            continue;
        }
        else
        {
            get(x2,y2);continue;
        }
    }
    return 0;
}