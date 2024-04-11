#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main()
{
    int n,d;
    string s;
    cin>>n>>d>>s;
    int a[n];
    memset(a,255,sizeof(a));
    a[0]=0;
    for(int i=0;i<n;i++)
        if(s[i]=='1'&&a[i]!=-1)
            for(int j=1;j<=d;j++)
                if(i+j<n&&s[i+j]=='1'&&
                   (a[i+j]==-1||a[i+j]>a[i]+1))
                   a[i+j]=a[i]+1;
    cout<<a[n-1];
}