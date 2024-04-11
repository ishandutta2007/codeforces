#include<iostream>
using namespace std;
int main()
{
int n,k,i,p1=0,p2=0;
string s;
cin>>n>>k>>s;
if(k==2)
{
for(i=0;i<n;i++)
{
if(s[i]-'A'!=i%2) p1++;
else p2++;
}
cout<<min(p1,p2)<<endl;
if(p1<p2) for(i=0;i<n;i++) cout<<char('A'+i%2);
else for(i=0;i<n;i++) cout<<char('A'+1-(i%2));
}

else
{
for(i=1;i<n;i++)
{
if(s[i]==s[i-1])
{
p1++;
s[i]='A';
while(s[i]==s[i-1] || s[i]==s[i+1]) s[i]++;
}
}
cout<<p1<<endl<<s;
}
return 0;
}