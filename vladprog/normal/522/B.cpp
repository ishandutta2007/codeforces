#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cin>>n;
    int w[n],h[n],s=0,m1=0,m2=0;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>h[i];
        s+=w[i];
        m2=max(m2,h[i]);
        if(m1<m2)
            swap(m1,m2);
    }
    for(int i=0;i<n;i++)
        if(h[i]==m1)
            cout<<(s-w[i])*m2<<' ';
        else
            cout<<(s-w[i])*m1<<' ';
}