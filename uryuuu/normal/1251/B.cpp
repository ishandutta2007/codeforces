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
string s;
int sum[maxn];
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int a=0,b=0;
        int aa=0,bb=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            sum[i]=s.length();
            for(int j=0;j<s.length();j++)
            {
                if(s[j]=='0')
                    a++;
                else
                    b++;
            }
            if(s.length()%2==0)
                aa++;
            else
                bb++;
        }
        a%=2;
        b%=2;
        if(a+b>bb)
            cout<<n-1<<endl;
        else
            cout<<n<<endl;
    }
    return 0;
}