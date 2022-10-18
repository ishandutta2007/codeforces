#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int k=0,p=0;
    for(int i=0;i<s.length();i++)
    {
        int t=s[i]-'a';
        k+=min((p+26-t)%26,(t+26-p)%26);
        p=t;
    }
    cout<<k;
}