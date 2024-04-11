#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=1e5+200;
const ll mod=1e9+7;

vi v;

int solve()
{
    if(v.empty())return 0;
    if(v.size()%2)return -1;
    int cnt=0;
    for(auto i:v)if(i)cnt++;
    if(cnt!=v.size()/2)return -1;

    int num1=0,num2=0;
    for(auto i:v)
    {
        if(i)
        {
            num1++;
            num2--;
        }
        else
        {
            num2++;
            num1--;
        }
        num1=max(0,num1);
        num2=max(0,num2);
    }
    return num1+num2;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n;cin>>n;
    string a,b;cin>>a>>b;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])v.push_back(a[i]-'0');
    }
    cout<<solve();
    return 0;
}