#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
struct date{
    int num;
    int id;
}b[200002];
bool cmp(date &x,date &y)
{
    return x.num>y.num;
}
int check(int q)
{
    int cnt=0;
    for(int i=1;i<200000;i++)
        cnt+=b[i].num/q;
    if(cnt>=k)
        return 1;
    return 0;
}
int main()
{
    int a;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        b[a].id=a;
        b[a].num++;
    }
    sort(b+1,b+200001,cmp);
    int l=1,r=n,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    mid=l-1;
    int ans=0;
    for(int i=1;i<200000;i++)
    {
        if((ans+b[i].num/mid)>=k)
        {for(int j=0;j<k-ans;j++)
            cout<<b[i].id<<' ';
            break;
        }
        else
        {
            ans+=b[i].num/mid;
            for(int j=0;j<b[i].num/mid;j++)
                cout<<b[i].id<<' ';
        }
    }
    return 0;
}