#include<bits/stdc++.h>
using namespace std;
string s;
int up,l;
int main()
{
    cin>>s;
    if(s.size()&1)
      {
        printf("-1");
        return 0;
      }
    for(int i=0;i<s.size();i++)
      {
        if(s[i]=='U')
          up++;
        if(s[i]=='D')
          up--;
        if(s[i]=='L')
          l++;
        if(s[i]=='R')
          l--;
      }
    printf("%d",(abs(up)+abs(l))/2);
    return 0;
}