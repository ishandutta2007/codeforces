#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
        cin>>b[i];
    int d=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(b[j]%a[i]==0)
                d=max(d,b[j]/a[i]);
    int k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(b[j]%a[i]==0&&d==b[j]/a[i])
                k++;
    cout<<k;
}