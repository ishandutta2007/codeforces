#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,n;
        cin>>n;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        int aa=0,bb=0,cc=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='R')aa++;
            else if(s[i]=='P')bb++;
            else cc++;
        }
        int sum=min(a,cc)+min(b,aa)+min(c,bb);
        if(sum<(n+1)/2)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            char ans[110]={0};
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='R')
                {
                    if(b)
                    {
                        ans[i]='P';
                        b--;
                    }
                }
                if(s[i]=='P')
                {
                    if(c)
                    {
                        ans[i]='S';
                        c--;
                    }
                }
                if(s[i]=='S')
                {
                    if(a)
                    {
                        ans[i]='R';
                        a--;
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                if(ans[i]==0)
                {
                    if(a)
                    {
                        ans[i]='R';
                        a--;
                    }
                    else if(b)
                    {
                        ans[i]='P';
                        b--;
                    }
                    else
                    {
                         ans[i]='S';
                         c--;
                    }
                }
            }
            cout<<"YES"<<endl;
            printf("%s\n",ans);
        }
    }
    return 0;
}