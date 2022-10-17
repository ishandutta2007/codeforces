#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;string s;
        cin>>n>>s;
        int e = -1;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='8') {e=i;break;}
        }
        if(e==-1 || s.size()-e<11)
        {
            cout << "NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
}