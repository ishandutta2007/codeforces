#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

bool ans[maxn];

int main()
{
    string str;
    cin>>str;
    int ma=0;
    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i]>=ma)
        {
            ans[i]=1;
            ma=str[i];
        }
    }
    for(int i=0;i<str.length();i++)
    {
        if(ans[i])
            cout<<str[i];
    }
    return 0;
}