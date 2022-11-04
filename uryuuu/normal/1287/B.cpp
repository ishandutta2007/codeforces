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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll  Mod=998244353;
 
string s[1505],ss;
unordered_map<string,int>mp;
 
int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        mp[s[i]]++;
    }
    int d;
    int sa,sb;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ss="";
            for(int u=0;u<k;u++)
            {
                if(s[i][u]=='S')
                    sa=0;
                else if(s[i][u]=='E')
                    sa=1;
                else
                    sa=2;
                
                if(s[j][u]=='S')
                    sb=0;
                else if(s[j][u]=='E')
                    sb=1;
                else
                    sb=2;
                
                d=(6-sa-sb)%3;
                if(d==0)
                    ss+='S';
                else if(d==1)
                    ss+='E';
                else
                    ss+='T';
//                cout<<ss<<endl;
            }
//            cout<<s[i]<<' '<<s[j]<<' '<<ss<<endl;
            if(mp[ss])
                sum++;
        }
    }
    cout<<sum/3<<endl;
    return 0;
}