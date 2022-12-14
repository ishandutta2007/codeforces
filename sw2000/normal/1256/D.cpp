#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

ll n,k;
string s;

void f()
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')cnt++;
        else if(cnt>=k)
        {
            for(int j=0;j<k;j++)
            {
                s[i-j]='1';
            }
            s[i-k]='0';
            for(int j=0;j<cnt-k;j++)
            {
                s[i-k-j-1]='1';
            }
            for(int j=0;j<i-cnt;j++)
                s[j]='0';

            return;
        }
        else
        {
            k-=cnt;
        }
    }

    for(int i=0;i<n-cnt;i++)
        s[i]='0';
    for(int i=n-cnt;i<n;i++)
        s[i]='1';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>s;
        f();
        cout<<s<<endl;
    }
    return 0;
}