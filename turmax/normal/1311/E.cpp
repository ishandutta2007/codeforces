#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> a(5001);
int z[5001];
int h[5001];
bool go(int n,int d,int mi)
{
    if(n<=0)
    {
        return false;
    }
    if(n==1)
    {
        if(d==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(d>(n*(n-1))/2)
    {
        return false;
    }
    if(d==0 && n!=1)
    {
        return false;
    }
    if(z[n-1]<=(d-n+1) && h[n-1]>=(d-n+1))
    {
        go(n-1,d-n+1,mi+1);
        a[mi+1]=mi;
        return true;
    }
    if(z[n-2]<=(d-n+1) && h[n-2]>=(d-n+1))
    {
        go(n-2,d-n+1,mi+2);
        a[mi+1]=mi;
        a[mi+2]=mi;
        return true;
    }
    int x1=(n-1)/2;
    int x2=(n-1-x1);
    int y1=z[x1];
    int y2=d-n+1-y1;
    int z1=mi+1;
    int z2=mi+1+x1;
    //cout<<x1<<" "<<y1<<" "<<z1<<"    "<<x2<<" "<<y2<<" "<<z2<<endl;
    if(go(x1,y1,z1) && go(x2,y2,z2))
    {
        a[z1]=mi;
        a[z2]=mi;
        return true;
    }
    return false;
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    z[1]=0;
    z[0]=0;
    h[0]=0;
    h[1]=0;
    for(int i=2;i<=5000;++i)
    {
        h[i]=i*(i-1)/2;
        z[i]=1e18;
        for(int j=0;j<i;++j)
        {
            z[i]=min(z[i],i-1+z[j]+z[i-1-j]);
        }
    }
    /*for(int i=0;i<20;++i)
    {
        cout<<z[i]<<endl;
    }*/
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
        int n,d;
        cin>>n>>d;
        for(int i=0;i<5001;++i)
        {
            a[i]=(-1);
        }
        if(!go(n,d,1))
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            for(int i=2;i<=n;++i)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}