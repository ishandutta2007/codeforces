#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x) {return po(x,p-2);}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector <int> v;
    for(int i=0;i<10;++i) v.push_back(0);
    for(int i=0;i<k;++i) {int x;cin>>x;v[x]=1;}
    int t=(n/2);
    vector <int> ans;
    int lst=9;
    while(!v[lst]) lst--;
    for(int i=0;i<10;++i) ans.push_back(0);
    ans.push_back(v[lst]);
    for(int i=(lst*t-1);i>=0;i--)
    {
        int sum1=0;
        for(int j=1;j<=lst;++j)
        {
            sum1+=((ans[ans.size()-j]*v[lst-j])%p)*(i+j);
            sum1%=p;
            sum1-=((ans[ans.size()-j]*v[lst-j])%p)*(lst-j)*t;
            sum1%=p;
        }
        sum1%=p;
        sum1+=p;
        sum1%=p;
        //cout<<sum1<<" sum1 "<<endl;
        ans.push_back((sum1*inv(lst*t-i))%p);
    }
    int res=0;
    for(auto h:ans) {res+=(h*h);res%=p;}
    cout<<res;
    return 0;
}