#include <bits/stdc++.h>

using namespace std;
#define int long long
int a[3];
bool used[3];
int h[3];
void to(int i,int j)
{
    if(a[i]<a[j])
    {
        swap(a[i],a[j]);
        swap(h[i],h[j]);
        swap(used[i],used[j]);
    }
}
void f(int x)
{
    //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    for(int i=0;i<3;++i) used[i]=false;
    cout<<x<<endl;
    int ans;
    cin>>ans;
    if(ans<=0) exit(0);
    ans--;
    for(int i=0;i<3;++i)
    {
        if(h[i]==ans)
        {
            ans=i;
            break;
        }
    }
    used[ans]=true;
    a[ans]+=x;
    to(0,1);to(0,2);to(1,2);to(0,1);to(0,2);to(1,2);
}
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>a[0]>>a[1]>>a[2];
    for(int i=0;i<3;++i)
    {
        h[i]=i;
    }
    to(0,1);to(0,2);to(1,2);to(0,1);to(0,2);to(1,2);
    //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    //cout<<h[0]<<" "<<h[1]<<" "<<h[2]<<endl;
    cout<<"First"<<endl;
    f(1);
    while(true)
    {
        //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        if(used[1] && 2*a[1]>(a[2]+a[0]))
        {
            f(2*a[1]-a[2]-a[0]);
            if(used[0])
            {
                f(a[0]-a[1]);
            }
            if(used[2])
            {
                f(a[0]-a[1]);
                f(a[0]-a[2]);
                f(a[0]-a[1]);
                f(a[0]-a[1]);
                f(a[0]-a[1]);
            }
        }
        else if((a[0]-a[1])<(a[1]-a[2]))
        {
            f(a[0]-a[1]);
        }
        else
        {
            f(a[1]-a[2]);
        }
    }
    return 0;
}