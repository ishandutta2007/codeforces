#include <bits/stdc++.h>

using namespace std;
#define int long long
int sz=200;
void get(int x)
{
    cout<<"! "<<x<<endl;
    exit(0);
}
int query1(int x,int y)
{
    vector <pair<int,int> > v;
    for(int i=1;i<=sz;++i) for(int j=1;j<=sz;++j) if(i%x==0 && j%y==0) v.push_back({i,j});
    cout<<"? "<<v.size()<<endl;
    for(auto h:v) cout<<h.first<<' '<<h.second<<' ';
    cout<<endl;
    //cout<<x<<' '<<y<<endl;
    //cout<<x<<' '<<y<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int s=query1(1,1);
    int low=0;
    int up=8;
    int res=0;
    while(true)
    {
        if((up-low)==1)
        {
            //cout<<low<<' '<<up<<endl;
            int h=abs(s-res)/(1<<(up-1));
            int b=(s/h);
            //cout<<b<<' '<<h<<endl;
            get(2*b+2*h-4);
        }
        int mid=(low+up)/2;
        int ans1=query1((1<<mid),1);
        if(ans1==(s/(1<<mid)) && s%(1<<mid)==0)
        {
            low=mid;
        }
        else
        {
            up=mid;
            res=ans1*(1<<mid);
            //cout<<res<<" res "<<endl;
        }
    }
    return 0;
}