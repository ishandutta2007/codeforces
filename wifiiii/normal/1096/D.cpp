#include<iostream>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxn = 1e5 + 10;
ll a[maxn],h[maxn],ha[maxn],har[maxn],hard[maxn];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        if(s[i-1]=='h') h[i]=h[i-1]+a[i];
        else h[i]=h[i-1];
        if(s[i-1]=='a') ha[i]=min(h[i-1],ha[i-1]+a[i]);
        else ha[i]=ha[i-1];
        if(s[i-1]=='r') har[i]=min(ha[i-1],har[i-1]+a[i]);
        else har[i]=har[i-1];
        if(s[i-1]=='d') hard[i]=min(har[i-1],hard[i-1]+a[i]);
        else hard[i]=hard[i-1];
    }
    cout<<hard[n]<<endl;
}