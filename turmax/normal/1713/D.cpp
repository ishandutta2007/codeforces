#include <bits/stdc++.h>

using namespace std;
#define int long long
int que(int x,int y)
{
    cout<<"? "<<x<<' '<<y<<endl;
    int ans;cin>>ans;
    if(ans==(-1)) exit(0);
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> v(1<<n);iota(v.begin(),v.end(),1);
        vector<int> v1;
        while(v.size()>=4)
        {
            v1.clear();
            for(int i=0;i<v.size();i+=4)
            {
                int x=v[i];int y=v[i+1];int z=v[i+2];int t=v[i+3];
                int ans1=que(x,z);
                if(ans1==0)
                {
                    int ans2=que(y,t);
                    if(ans2==1) v1.push_back(y);
                    else v1.push_back(t);
                }
                else if(ans1==1)
                {
                    int ans2=que(x,t);
                    if(ans2==1) v1.push_back(x);
                    else v1.push_back(t);
                }
                else
                {
                    assert(ans1==2);
                    int ans2=que(y,z);
                    if(ans2==1) v1.push_back(y);
                    else v1.push_back(z);
                }
            }
            v=v1;
        }
        if(v.size()==1)
        {
            cout<<"! "<<v[0]<<endl;
            continue;
        }
        else
        {
            int ans=que(v[0],v[1]);
            if(ans==1) {cout<<"! "<<v[0]<<endl;}
            else {cout<<"! "<<v[1]<<endl;}
        }
    }
    return 0;
}