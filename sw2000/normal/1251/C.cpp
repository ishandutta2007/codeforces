#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string a,b;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]%2)a+=s[i];
            else b+=s[i];
        }
        s="";
        int i=0,j=0;
        while(1)
        {
            if(i==a.length())
            {
                for(;j<b.length();j++)
                    s+=b[j];
                break;
            }
            if(j==b.length())
            {
                for(;i<a.length();i++)
                    s+=a[i];
                break;
            }
            if(a[i]<b[j])
            {
                s+=a[i++];
            }
            else s+=b[j++];
        }
        cout<<s<<endl;
    }
    return 0;
}