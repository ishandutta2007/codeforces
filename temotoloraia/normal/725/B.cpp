#include <bits/stdc++.h>
using namespace std;
long long a,ans;
char b;
int main ()
{
	cin>>a>>b;
	ans=(a-1)/4*16;
	if (a%2==0)ans+=7;
	if (b>='d')ans+=6-b+'a';
	else ans+=3+b-'a'+1;
	cout<<ans<<endl;
}