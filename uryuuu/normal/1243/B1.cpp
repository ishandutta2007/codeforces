#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=500005;
int a[30],b[2000];
int main()
{
    sync;
    int T;
    cin>>T;
    string s;
    string t;
    while(T--)
    {
        mm(a);
        mm(b);
        int n;
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            a[int(s[i]-'a')]++;
        }
        cin>>t;
        for(int i=0;i<n;i++)
        {
            a[int(t[i]-'a')]++;
        }
        
        int f=0;
        for(int i=0;i<28;i++)
        {
            if(a[i]%2)
            {
                cout<<"No"<<endl;
                f=1;
                break;
            }
        }
        int cnt=0;
        if(f==0)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]!=t[i])
                {
                    b[cnt]=int(s[i]-'a');
                    cnt++;
                }
                
            }
            if(cnt>2)
                cout<<"No"<<endl;
            else
            {
                if(b[0]==b[1])
                    cout<<"Yes"<<endl;
                else
                    cout<<"No"<<endl;
            }
        }
    }
    return 0;
}