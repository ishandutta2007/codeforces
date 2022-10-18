#include<bits/stdc++.h>

using namespace std;

int main ()
{
    string s,t;
    cin>>s>>t;
    int l,r,k;
    for(l=0,k=0;(l<t.length())&&(k<s.length());l++)
        if(t[l]==s[k])
            k++;
    for(r=t.length()-1,k=s.length()-1;(r>=0)&&(k>=0);r--)
        if(t[r]==s[k])
            k--;
    cout<<max(0,r-l+2);
}