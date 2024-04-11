#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s[101],t[101];
    int n,i,j,sum=0;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>s[i]>>t[i];
        for (j=i-1;j>=1;j--)
        if (s[i]==s[j]&&t[i]==t[j])
        {sum++;break;}
    }
    cout<<n-sum;
    return 0;
}