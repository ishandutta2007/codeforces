#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int main()
{
    int n,a1=0,a2=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='n')a1++;
        if(s[i]=='z')a2++;
    }

    for(int i=0;i<a1;i++)printf("1 ");
    for(int i=0;i<a2;i++)printf("0 ");

    return 0;
}