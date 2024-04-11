#include<bits/stdc++.h>

#define w second
#define h first

using namespace std;

int main ()
{
    int n;
    cin>>n;
    pair<int,int> a[n+1];
    int m=0,sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].w>>a[i].h;
        if(a[i].w>a[i].h)
            swap(a[i].w,a[i].h);
        m=max(m,min(a[i].w,a[i].h));
        sum+=a[i].w;
    }
    a[n+1]=make_pair(0,0);
    sort(a,a+n);
    reverse(a,a+n);
    int s=sum*a[0].h;
    //cout<<sum<<'*'<<a[0].h<<'='<<sum*a[0].h<<endl;
    for(int i=0;i<n;i++)
    {
        sum+=a[i].h-a[i].w;
        s=min(s,sum*max(a[i+1].h,m));
        //cout<<i<<':'<<sum<<'*'<<max(a[i+1].h,m)<<'='<<sum*max(a[i+1].h,m)<<endl;
    }
    cout<<s;
}