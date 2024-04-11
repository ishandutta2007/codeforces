#include <bits/stdc++.h>
using namespace std;
long long v[3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a,b,c,t,n,m,i,j;
    cin>>a>>b>>c;
    cout<<"First\n";
    long long mx=a;
    mx=max(mx,b);
    mx=max(mx,c);
    cout<<mx*3-a-b-c<<'\n';
    cout.flush();
    int x;
    cin>>x;
    if(x==0)
        return 0;
    long long idk=mx*3-a-b-c;
    if(x==1)
        a+=mx*3-a-b-c;
    else if(x==2)
        b+=mx*3-a-b-c;
    else
        c+=mx*3-a-b-c;
    v[0]=a;
    v[1]=b;
    v[2]=c;
    sort(v,v+3);
    if(v[2]==mx+(idk))
    {
        cout<<v[2]+v[2]-v[0]-v[1]<<'\n';
        cout.flush();
        cin>>x;
        if(x==1)
            a+=v[2]+v[2]-v[0]-v[1];
        else if(x==2)
            b+=v[2]+v[2]-v[0]-v[1];
        else
            c+=v[2]+v[2]-v[0]-v[1];
        v[0]=a;
        v[1]=b;
        v[2]=c;
        sort(v,v+3);
        cout<<v[2]-v[1]<<'\n';
        cout.flush();
    }
    else
    {
        cout<<v[2]-v[1]<<'\n';
        cout.flush();
        cin>>x;
    }
    return 0;
}