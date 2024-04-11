#include <bits/stdc++.h>
using namespace std;
int T;
long long ans1,ans2;
char ch[10007];
int main()
{
    cin>>T;
    while (T--)
    {
        string s;
        cin>>s;
        bool check=1;
        int i=0;
        while (i<s.length()&&s[i]>='A'&&s[i]<='Z') i++;
        while (i<s.length()&&s[i]>='0'&&s[i]<='9') i++;
        if (i>=s.length())
        {
        i=0,ans1=0,ans2=0;
        while (i<s.length()&&s[i]>='A'&&s[i]<='Z') {ans1=26LL*ans1+s[i]-'A'+1,i++;}
        while (i<s.length()&&s[i]>='0'&&s[i]<='9') {ans2=10LL*ans2+s[i]-'0',i++;}
        cout << "R"<<ans2<<"C"<<ans1<<endl;
        } else
        {
            i=1,ans1=0,ans2=0;
        while (i<s.length()&&s[i]>='0'&&s[i]<='9') {ans1=10LL*ans1+s[i]-'0',i++;}
        ++i;
        while (i<s.length()&&s[i]>='0'&&s[i]<='9') {ans2=10LL*ans2+s[i]-'0',i++;}
        int cnt=0;
        while (ans2>0)
        {
            char c=((ans2-1)%26)+'A';
            ch[++cnt]=c;
            ans2=(ans2-1)/26;
        }
        for (int i=cnt;i;i--) cout <<ch[i];
        cout<<ans1<<endl;
        }
    }
    return 0;
}