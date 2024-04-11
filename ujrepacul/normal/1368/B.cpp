#include <bits/stdc++.h>
using namespace std;
char v[]="codeforces";
long long cnt[15];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>n;
    long long sc=1;
    int pz=0;
    for(i=0;i<=9;++i)
        cnt[i]=1;
    while(sc<n)
    {
        ++cnt[pz];
        sc=1;
        for(i=0;i<=9;++i)
            sc=sc*1LL*cnt[i];
        ++pz;
        if(pz==10)
            pz=0;
    }
    for(i=0;i<=9;++i)
    {
        for(j=1;j<=cnt[i];++j)
            cout<<v[i];
    }
    return 0;
}