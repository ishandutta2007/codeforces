#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    bool ok=false;
    for(int i=0;i<n;i++)
    {
        if((i<=(n-3))&&(s[i]=='o')&&(s[i+1]=='g')&&(s[i+2]=='o'))
        {
            cout<<"***";
            ok=true;
            continue;
        }
        if((s[i]!='g')||(s[i+1]!='o'))
            ok=false;
        if(ok)
            i++;
        else
            cout<<s[i];
    }
}