#include<iostream>
#include<algorithm>
using namespace std;
__int64 a[3000000],k,c;
char s[1520],v[30];
int main()
{
	cin>>s>>v>>k;
	for(int i=0;s[i];i++)
		for(__int64 j=i,kk=k,h=0;s[j]&&(v[s[j]-'a']>'0'||kk--);j++)
			a[c++]=h=(h*131)^s[j];
	sort(a,a+c);
	cout<<unique(a,a+c)-a;
}