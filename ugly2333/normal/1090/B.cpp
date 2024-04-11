//CF1090B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111;
const string s1 = "\\begin{thebibliography}{99}";
const string s2 = "\\end{thebibliography}";
int n,m;
string s,a[N],b[N],c[N];
string g(int i){
	string t="";
	while(s[i]!='}'){
		t+=s[i];
		i++;
	}
	//cout<<t<<endl;
	return t;
}
int main()
{
	int i,j,f;
	f=0;
	while(1){
		getline(cin,s);
		if(s==s1){
			f=1;
			continue;
		}
		if(s==s2)
			break;
		if(!f){
			for(i=0;i<s.length();i=i+1)
				if(s[i]=='\\')
					a[++n]=g(i+6);
		}
		else{
			b[++m]=g(9);
			c[m]=s;
		}
	}
	f=1;
	for(i=1;i<=n;i=i+1)
		if(a[i]!=b[i])
			f=0;
	if(f){
		cout<<"Correct";
		return 0;
	}
	cout<<"Incorrect"<<endl<<s1<<endl;
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=n;j=j+1)
			if(a[i]==b[j])
				break;
		cout<<c[j]<<endl;
	}
	cout<<s2;
	return 0;
}