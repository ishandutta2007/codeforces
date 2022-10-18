#include<bits/stdc++.h>

#define si <string,int>
#define psi pair si
#define msi map si

using namespace std;

map si m;

void tolower(string &str)
{
    for(int i=0;i<str.length();i++)
        if(str[i]>'Z')
            str[i]=(char)(int(str[i])-(int)'a'+(int)'A');
}

int main ()
{
    int n;
    cin>>n;
    m.insert(psi("POLYCARP",1));
    int ans=1;
    for(int i=0;i<n;i++)
    {
        string s1;
        cin>>s1;
        tolower(s1);
        string s2;
        cin>>s2;
        cin>>s2;
        tolower(s2);
        msi::iterator i1=m.find(s1);
        msi::iterator i2=m.find(s2);
        int k;
        if(i1==m.end())
            k=i2->second+1;
        else
        {
            k=max(i1->second,i2->second+1);
            m.erase(i1);
        }
        m.insert(psi(s1,k));
        ans=max(k,ans);
    }
    cout<<ans;
}