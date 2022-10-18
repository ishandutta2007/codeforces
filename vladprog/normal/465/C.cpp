#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,p;
    string s;
    cin>>n>>p>>s;
    char m=(char)((int)'a'+p);
    s="  "+s;
    int i;
    for(i=n+1;i>=2;i--)
    {
        for(s[i]++;s[i]<m;s[i]++)
            if(s[i]!=s[i-1]&&s[i]!=s[i-2])
                break;
        if(s[i]!=m)
            break;
    }
    if(i<2)
        return cout<<"NO\n", 0;
    for(i++;i<=n+1;i++)
    {
        for(s[i]='a';s[i]<m;s[i]++)
            if(s[i]!=s[i-1]&&s[i]!=s[i-2])
                break;
        if(s[i]==m)
            return cout<<"NO\n", 0;
    }
    s=string(s,2);
    cout<<s;
}