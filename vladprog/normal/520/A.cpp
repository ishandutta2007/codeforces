#include<bits/stdc++.h>

using namespace std;

bool a['Z'+1];

int main ()
{
    int n;
    string s;
    cin>>n>>s;
    //if(n<26)
    //    return cout<<"NO", 0;
    for(int i=0;i<n;i++)
    {
        a[s[i]]=true;
        a[(char)((int)s[i]+(int)'A'-(int)'a')]=true;
    }
    for(char c='A';c<='Z';c++)
        if(!a[c])
            return cout<<"NO", 0;
    cout<<"YES";
}