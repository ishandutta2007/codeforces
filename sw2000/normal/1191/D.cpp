#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;

void aa()
{
    cout<<"sjfnb";
    exit(0);
}

void bb()
{
    cout<<"cslnb";
    exit(0);
}

int main()
{
    int n,a[maxn],visit=0,pre=0;
    ll sum=0,need=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=(ll)a[i];
    }
    sort(a,a+n);
    
    if(a[0]==0&&a[1]==0)
    {
        bb();
    }

    int repeat=0;
    for(int i=0;i<n;i++)
    {
        if(i>1&&a[i]==a[i-1]&&a[i]==a[i-2]+1)
        {
            bb();
        }
        if(i&&a[i]==a[i-1])repeat++;
        if(repeat>1)bb();
    }


    sum-=(ll)n*(n-1)/2;

    if(sum&1)cout<<"sjfnb";
    else cout<<"cslnb";
    return 0;
}