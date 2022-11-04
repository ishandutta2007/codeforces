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
const int maxn=500005;
string s;
int a[maxn],b[maxn];
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int ac=0;
        int bc=0;
        for(int i=0;i<s.length();i++)
        {
            if(int(s[i]-'0')%2==0)
                a[ac++]=int(s[i]-'0');
            else
                b[bc++]=int(s[i]-'0');
        }
        a[ac]=99999999;
        b[bc]=99999999;
        int q=0,r=0;
        for(int i=0;i<s.length();i++)
        {
            if(a[q]>b[r])
            {
                cout<<b[r];
                r++;
            }
            else
            {
                cout<<a[q];
                q++;
            }
        }
        cout<<endl;
    }
    return 0;
}