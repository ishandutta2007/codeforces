#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
string s;
cin>>n>>m;
cin>>s;
sort(s.begin(),s.end());
int l=-1,p=0;
for(int i=0; m&&i<n;i++)
if(s[i]>=l+2)l=s[i],p+=s[i]-'a'+1,m-=1;
if(m)cout<<-1;
else cout<<p;
}