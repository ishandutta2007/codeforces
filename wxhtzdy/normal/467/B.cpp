#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,m,k;
    cin>>n>>m>>k;
    m++;
    int a[m];
    for(int i=0;i<m;++i) cin>>a[i];
    int cnt=0;
    for(int i=0;i<m-1;++i)
    {
        for(int j=m-1;j<m;++j)
        {
            int d=0;
            for(int l=0;l<=n;++l)
            {
                if((a[i]&(1<<l))!=(a[j]&(1<<l))) ++d;
            }
            if(d<=k) ++cnt;
        }
    }
    cout<<cnt;
}