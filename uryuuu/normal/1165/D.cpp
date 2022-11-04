#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
using namespace std;
ll a[400];
int cnt(ll sss)
{
    int ct=0;
    for(ll i=1;i*i<=sss;i++)
    {
        if(sss%i==0)
        {
            if(i*i==sss)
                ct++;
            else
                ct+=2;
        }
    }
    return ct;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        mm(a);
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        ll sum=a[0]*a[n-1];
        int ff=0;
        for(int i=0;i<(n+1)/2;i++)
        {
            if(a[i]*a[n-1-i]!=sum)
            {
                ff=1;
                break;
            }
        }
        if(ff==1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(cnt(sum)-2!=n)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<sum<<endl;
    }
    return 0;
}