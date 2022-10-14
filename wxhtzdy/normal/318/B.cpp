#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

char s[N];

int main()
{
    scanf("%s",&s);
    int n=(int)strlen(s),cnt=0;
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        if (i+4<n && s[i]=='h' && s[i+1]=='e' && s[i+2]=='a' && s[i+3]=='v' && s[i+4]=='y')
            cnt++;
        if (i+4<n && s[i]=='m' && s[i+1]=='e' && s[i+2]=='t' && s[i+3]=='a' && s[i+4]=='l')
            ans+=cnt;
    }
    printf("%lld",ans);
}