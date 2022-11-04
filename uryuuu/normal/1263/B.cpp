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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
 
string s[20];
map<string,int>mp;
int vis[20];
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mm(vis);
        int cnt=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            mp[s[i]]++;
            vis[int(s[i][0]-'0')]++;
        }
        for(int i=0;i<n;i++)
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
                continue;
            else
            {
                for(int j=0;j<=9;j++)
                {
                    if(vis[j]==0)
                    {
                        cnt++;
                        s[i][0]=char('0'+j);
                        vis[j]=1;
                        break;
                        
                    }
                }
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<n;i++)
            cout<<s[i]<<endl;
    }
    return 0;
}