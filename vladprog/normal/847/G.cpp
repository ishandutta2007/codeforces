#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[7]={};
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<7;j++)
            a[j]+=s[j]-'0';
    }
    int m=0;
    for(int i=0;i<7;i++)
        m=max(m,a[i]);
    cout<<m;
}