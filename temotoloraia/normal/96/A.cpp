#include<iostream>
#include<string>
using namespace std;
int k,i;
string s;
int main()
{
	cin>>s;
 k=s.size ();
 for(i=0;i<k-6;i++)
 if(s[i]==s[i+1] && s[i]==s[i+2] && s[i]==s[i+3] && s[i]==s[i+4] && s[i]==s[i+5] && s[i]==s[i+6])
 {
 cout<<"YES";
 return 0;}
 cout<<"NO";
 return 0;
}