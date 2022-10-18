#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int H=1e5;

int a[H],s[H];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h;
    cin>>h;
    for(int i=0;i<=h;i++)
        cin>>a[i];
    s[0]=a[0];
    for(int i=1;i<=h;i++)
        s[i]=s[i-1]+a[i];
    bool ok=false;
    for(int i=1;i<=h;i++)
        if(a[i-1]>=2&&a[i]>=2)
            ok=true;
    if(!ok)
        cout<<"perfect",exit(0);
    cout<<"ambiguous\n";
    cout<<0<<" ";
    for(int i=1;i<=h;i++)
        for(int j=1;j<=a[i];j++)
            cout<<s[i-1]<<" ";
    cout<<"\n"<<0<<" ";
    for(int i=1;i<=h;i++)
        for(int j=1;j<=a[i];j++)
            if(a[i-1]>=2&&j>=2)
                cout<<s[i-1]-1<<" ";
            else
                cout<<s[i-1]<<" ";
}