#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
int tt;
cin>>tt;
while(tt--)
{
int n;
cin>>n;
string s[n];
for(int i=0;i<n-2;i++)
cin>>s[i];
vector<char> ans;
ans.pb(s[0][0]);
ans.pb(s[0][1]);
for(int i=1;i<n-2;i++)
{
if(ans.back()!=s[i][0])ans.pb(s[i][0]);
ans.pb(s[i][1]);
}
if(ans.size()<n)ans.pb('b');
for(char wtf:ans)cout<<wtf;
cout<<"\n";
}
}