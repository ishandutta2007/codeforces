#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;string s;
    scanf("%i",&n);
    cin >> s;
    for(i=0;i+1<n;i++) if(s[i]!=s[i+1]) return 0*printf("YES\n%c%c\n",s[i],s[i+1]);
    printf("NO\n");
    return 0;
}