#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;

void solve()
{
    int n;cin>>n;
    vi v={1};
    int st;
    for(int i=2;i<=n;i++)
    {
        cout<<"? "<<v.size()<<' '<<1<<endl;
        for(auto j:v)cout<<j<<' ';cout<<endl;
        cout<<i<<endl;

        int op;cin>>op;
        if(op)
        {
            st=i;
            break;
        }

        v.push_back(i);
    }

    vi ans{};
    int l=1,r=st-1;
    while(l!=r)
    {
        int mid=l+r>>1;
        cout<<"? "<<mid-l+1<<" 1"<<endl;
        for(int i=l;i<=mid;i++)cout<<i<<' ';
        cout<<endl;
        cout<<st<<endl;

        int op;cin>>op;
        if(op)r=mid;
        else l=mid+1;
    }
    for(int i=1;i<st;i++)if(i!=l)
        ans.push_back(i);

    for(int i=st+1;i<=n;i++)
    {
        cout<<"? 1 1"<<endl;
        cout<<st<<endl;
        cout<<i<<endl;
        int op;cin>>op;
        if(!op)ans.push_back(i);
    }
    cout<<"! ";
    cout<<ans.size()<<' ';
    for(auto i:ans)cout<<i<<' ';
    cout<<endl;
}
int main()
{
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}