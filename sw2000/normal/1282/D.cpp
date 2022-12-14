#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+10;
const ll mod=1e9+7;
int main()
{
    string s1,s2;
    for(int i=0;i<300;i++)
    {
        s1+="a";
        s2+="b";
    }
    int a,b;
    cout<<s1<<endl;
    cin>>a;
    cout<<s2<<endl;
    cin>>b;
    a=300-a;
    b=300-b;
    int len=a+b;
    string ans;
    for(int i=0;i<len;i++)
        ans+="b";
    int ret=a;
    for(int i=0;i<len-1;i++)
    {
        ans[i]='a';
        cout<<ans<<endl;
        int tmp;
        cin>>tmp;
        if(tmp>ret)
        {
            ans[i]='b';
        }
        else ret=tmp;
    }
    if(ret==1)ans[ans.size()-1]='a';
    cout<<ans<<endl;
    return 0;
}