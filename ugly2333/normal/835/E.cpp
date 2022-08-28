//CF 835E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int n,x,y;
int a[1111],s;
bool ask(){
	if(s==0)
		return 0;
	int i;
	cout<<"? "<<s;
	for(i=1;i<=s;i=i+1)
		cout<<' '<<a[i];
	cout<<endl;
	cin>>i;
	return (i==y)||(i==(x^y));
}
int main()
{
	int i,j,t,k,l,z;
	cin>>n>>x>>y;
	k=0;
	for(i=0;i<=9;i=i+1){
		s=0;
		for(j=1;j<=n;j=j+1){
			t=j>>i;
			if(!(t&1)){
				s++;
				a[s]=j;
			}
		}
		if(ask()){
			l=i;
			k+=(1<<i);
		}
	}
	//cout<<l<<endl;
	z=0;
	for(i=0;i<=9;i=i+1){
		if(i==l)
			continue;
		s=0;
		for(j=1;j<=n;j=j+1){
			t=j>>l;
			if(t&1)
				continue;
			t=j>>i;
			if(!(t&1)){
				s++;
				a[s]=j;
			}
		}
		if(!ask())
			z+=(1<<i);
	}
	k^=z;
	if(k>z)
		swap(k,z);
	cout<<"! "<<k<<' '<<z<<endl;
	return 0;
}