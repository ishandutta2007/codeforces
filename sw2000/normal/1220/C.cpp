#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll b[maxn][maxn];

int main()
{
    string s;
    cin>>s;
    char mi=127;
    for(int i=0;i<s.length();i++)
    {
        mi=min(mi,s[i]);
        if(s[i]==mi)puts("Mike");
        else puts("Ann");
    }
    return 0;
}