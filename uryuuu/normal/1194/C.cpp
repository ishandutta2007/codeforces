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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 50010
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int c[30];
int d[30];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,t,p;
        cin>>s>>t>>p;
        int ff=0;
        mm(c);
        mm(d);
        int ss=s.length();
        int tt=t.length();
        int pp=p.length();
        int j=0;
        for(int i=0;i<ss;i++)
        {
            int fff=0;
            for(;j<tt;j++)
            {
                if(s[i]==t[j])
                {
                    j++;
                    fff=1;
                    break;
                }
                else
                    c[t[j]-'a']++;
            }
            if(fff==0)
            {
                ff=1;
                break;
            }
        }
//        for(int i=0;i<28;i++)
//        {
//            cout<<c[i]<<' ';
//        }
//        cout<<ff;
        for(;j<tt;j++)
        {
            c[t[j]-'a']++;
        }
        for(int i=0;i<pp;i++)
        {
            d[p[i]-'a']++;
        }
        for(int i=0;i<28;i++)
        {
           if( c[i]>d[i])
           {
               ff=1;
               break;
           }
//            cout<<d[i]<<' ';
        }
        if(ff)
        {
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }
    return 0;
}