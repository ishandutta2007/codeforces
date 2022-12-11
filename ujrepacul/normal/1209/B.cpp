#include <bits/stdc++.h>
using namespace std;
char v[103];
int fv[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,m,k=0,x=0,t,s=0;
    cin>>n>>v;
    for(i=0;i<n;++i)
        fv[0]+=(v[i]=='1');
    s=fv[0];
    for(i=1;i<=n;++i)
    {
        int a,b;
        cin>>a>>b;
        char vl=v[i-1];
        int vlc=vl-'0';
        for(j=1;j<=100000;++j)
        {
            if((j-b)%a==0 && j>=b)
                vlc=1-vlc;
            fv[j]+=vlc;
            if(fv[j]>s)
                s=fv[j];
        }
    }
    cout<<s;
    return 0;
}