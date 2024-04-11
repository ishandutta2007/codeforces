#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int arr[maxn];

void a1()
{
    cout<<"Monocarp";
}

void a2()
{
    cout<<"Bicarp";
}

int main()
{
    int n,left=0,right=0,lw=0,rw=0;
    scanf("%d",&n);
    string s;
    cin>>s;
    for(int i=0;i<n/2;i++)
    {
        if(s[i]=='?')lw++;
        else left+=s[i]-'0';
    }

    for(int i=n/2;i<n;i++)
    {
        if(s[i]=='?')rw++;
        else right+=s[i]-'0';
    }

    if((lw-rw)%2!=0)a1();
    else
    {
        if((lw-rw)/2*9==right-left)a2();
        else a1();
    }
    return 0;
}