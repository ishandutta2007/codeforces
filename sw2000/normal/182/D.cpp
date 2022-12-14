#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

string sa,sb;
int la,lb,mi;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

bool f(int a)
{
    for(int i=0;i<a;i++)
        if(sa[i]!=sb[i])return 0;
    for(int i=a;i<la;i++)
        if(sa[i]!=sa[i-a])return 0;
    for(int i=a;i<lb;i++)
        if(sb[i]!=sb[i-a])return 0;
    return 1;
}

int main()
{
    cin>>sa>>sb;
    la=sa.length(),lb=sb.length(),mi;
    int len=gcd(la,lb);
    for(int i=1;i<=len;i++)
    {
        if(len%i==0)
        {
            if(f(i))
            {
                mi=i;
                break;
            }
        }
        if(i==len)
        {
            cout<<0;
            return 0;
        }
    }

    int ans=0;
    for(int i=mi;i<=len;i+=mi)
    {
        if(len%i==0)ans++;
    }
    cout<<ans;

    return 0;
}