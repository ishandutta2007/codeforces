#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
int main() 
{
ll i;
string c;
cin>>c;
vector <ll> a,b;
for (i=0;i<c.size();i++)
if (c[i]=='r') a.push_back(i+1); else b.push_back(i+1);
if (a.size())
for (i=0;i<a.size();i++)
cout<<a[i]<<endl;
if (b.size())
for (i=b.size()-1;i>=0;i--)
cout<<b[i]<<endl;
return 0;
}