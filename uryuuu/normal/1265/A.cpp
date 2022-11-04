//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=5005*16;

string s;
int main()
{
    sync;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(s.length()==1)
        {
            if(s[0]=='?')
                s[0]='a';
            cout<<s<<endl;
            continue;
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='?')
            {
                if(i==0)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(char('a'+j)!=s[i+1])
                        {
                            s[i]=char('a'+j);
                            break;
                        }
                    }
                }
                else if(i==s.length()-1)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(char('a'+j)!=s[i-1])
                        {
                            s[i]=char('a'+j);
                            break;
                        }
                    }
                }
                else
                {
                for(int j=0;j<3;j++)
                                                                    {
                                                                        if(char('a'+j)!=s[i-1]&&char('a'+j)!=s[i+1])
                                                                        {
                                                                            s[i]=char('a'+j);
                                                                            break;
                                                                        }
                                                                    }
                                                                }
                    
            }
        }
        int f=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                f=1;
                break;
            }
        }
        if(f)
            cout<<-1<<endl;
        else
            cout<<s<<endl;
    }
    
    return 0;
}