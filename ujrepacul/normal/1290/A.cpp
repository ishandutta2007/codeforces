#include <bits/stdc++.h>
using namespace std;
int v[3503];
int main()
{
    int cer,n,m,k,i,j=0,mx=0,mnmx=0,af,bf,id,jd,is,js,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        if(k>=m)
            k=m-1;
        int l=n-k;
        mx=0;
        for(i=1;i+l-1<=n;++i)
        {
            int dr=i+l-1;
            int mn=1000000001;
            int dstc=n-m;
            for(j=i;j+dstc<=dr;++j)
                mn=min(mn,max(v[j],v[j+dstc]));
            mx=max(mx,mn);
        }
        cout<<mx<<'\n';
    }
	return 0;
}