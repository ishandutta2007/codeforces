
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int Md=0,tmp=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(') tmp++;
        else tmp--;
        Md=max(Md,tmp);
    }
    int now = 0, tar = (1+Md)/2, now2 = 0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(')
        {
            if(now==tar) printf("1"),now2++;
            else printf("0"),now++;
        }
        else
        {
            if(now2) printf("1"),now2--;
            else printf("0"),now--;
        }
    }
}