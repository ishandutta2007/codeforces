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
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const ll Mod=1e9+7;
const int maxn=605;
int b[maxn],c[maxn];
int main()
{
    string s;
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>s;
        mm(b);
        mm(c);
        for(int i=0;i<s.length();i++)
        {
            b[i]=int(s[i]-'a');
        }
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            
            if(i==s.length()-1||b[i]!=b[i+1])
                c[cnt++]=b[i];
            else
            {
                i++;
            }
        }
        sort(c,c+cnt);
        int m=unique(c,c+cnt)-c;
        for(int i=0;i<m;i++)
        {
            cout<<char('a'+c[i]);
        }
        cout<<endl;
    }
    return 0;
}