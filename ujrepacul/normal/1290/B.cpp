#include <bits/stdc++.h>
using namespace std;
char v[200005];
int fv[200005][31]; /// oof WA degeaba :(
int main()
{
    int cer,n,m,k,i,j=0,mx=0,mnmx=0,af,bf,id,jd,is,js,t;
    cin>>(v+1);
    n=strlen(v+1);
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=29;++j)
            fv[i][j]+=fv[i-1][j];
        ++fv[i][v[i]-'a'+1];
    }
    cin>>m;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        if(a==b || v[a]!=v[b])
        {
            cout<<"Yes\n";
            continue;
        }
        int cnt=0;
        for(j=1;j<=29;++j)
        {
            if(fv[b][j]-fv[a-1][j])
                ++cnt;
        }
        if(cnt>=3)
        {
            cout<<"Yes\n";
        }
        else
            cout<<"No\n";
    }
	return 0;
}