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
        int vis[30]={0};
        string s;
        cin>>s;
        s+="#";
        s="#"+s;
        for(int i=1,cnt=0;i<s.length()-1;i++)
        {
            cnt++;
            if(s[i]!=s[i+1])
            {
                if(cnt%2)
                    vis[s[i]-'a']=1;
                cnt=0;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(vis[i])
                printf("%c",'a'+i);
        }
        puts("");
    }
    return 0;
}