#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 95542721
//map <ll,ll> a,b,c;
bool a(string s)
{
if (s.size()>4) 
if (s[0]=='m'&&s[1]=='i'&&s[2]=='a'&&s[3]=='o'&&s[4]=='.') return true;
else return false; else return false;
}
bool b(string s)
{
ll i=s.size()-5; 
if (s.size()>4)
if (s[i+0]=='l'&&s[i+1]=='a'&&s[i+2]=='l'&&s[i+3]=='a'&&s[i+4]=='.') return true;
else return false; else return false;
}
ll n,k1,k2,k3,k4;
string s;
int main() 
{
scanf("%d",&n);
getline(cin,s);
while (n--)
{
getline(cin,s);
if (a(s)^b(s))
{
if (a(s)) cout<<"Rainbow's"<<endl; else cout<<"Freda's"<<endl;
} else
cout<<"OMG>.< I don't know!"<<endl;
}
return 0;
}