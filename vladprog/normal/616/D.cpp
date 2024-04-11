#include <bits/stdc++.h>

using namespace std;

const int N=5e5,A=1e6+1;

int a[N],c[A];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int cnt=0,ans=0,l=-1,r=-1;
    for(int i=0,j=-1;i<n;i++)
    {
        for(j++;j<n;j++)
        {
            int ncnt=cnt;
            if(c[a[j]]==0)
                ncnt++;
            if(ncnt>k)
                break;
            if(c[a[j]]==0)
                cnt++;
            c[a[j]]++;
        }
        j--;
        if(j-i+1>ans)
            ans=j-i+1,l=i,r=j;
        c[a[i]]--;
        if(c[a[i]]==0)
            cnt--;
    }
    cout<<l+1<<" "<<r+1;
}