#include <bits/stdc++.h>
using namespace std;
int n,k;
long long ans;
int tmp;
string s,t;
int main()
{
cin>>n>>k;
cin>>s>>t;
for(int i=0;i<n;i++)
{
tmp*=2,tmp+=t[i]-s[i];
if(tmp+1>=k)
{
ans+=(long long)(n-i)*k;
break;
}
ans+=tmp+1;
}
cout<<ans;
return 0;
}