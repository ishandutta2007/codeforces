#include<iostream>
#include<string>
using namespace std;
int main()
{
string a;
int counter=0,count=0;
cin>>a;
string b="CODEFORCES";
for (int i=0;i<10;i++)
{
if (a[i]==b[i])
counter++;
else
break;
}
count=counter;
for (int i=0;i<10-count;i++)
{
if (a[a.size()-i-1]==b[b.size()-i-1])
counter++;
else
break;
}
if (counter>=10)
cout<<"YES";
else
cout<<"NO";
}