#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define maxn 500010
using namespace std;
string s,t;
int z[200005],w[200005];
int main()
{
    sync
    cin>>t>>s;
    int tlen=t.length();
    int j=0;
    int slen=s.length();
    for(int i=0;i<tlen;i++)
    {
        if(s[j]==t[i])
        {
//            cout<<"bbang";
            z[j++]=i;
        }
        if(j>=slen)
            break;
    }
    j=slen-1;
    for(int i=tlen-1;i>=0;i--)
    {
        if(s[j]==t[i])
        {
//            cout<<"bang";
            w[j--]=i;
        }
        if(j<0)
            break;
    }
    int zd=0;
    for(int i=0;i<slen-1;i++)
    {
        zd=max(w[i+1]-z[i]-1,zd);
    }
    zd=max(zd,w[0]);
    zd=max(zd,tlen-1-z[slen-1]);
    cout<<zd<<endl;
//    cout<<w[slen-1]<<' '<<z[slen-1]<<endl;
//    for(int i=0;i<slen;i++)
//        cout<<w[i];
//    cout<<slen;
    return 0;
}