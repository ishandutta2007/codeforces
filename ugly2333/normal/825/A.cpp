//CF 825A
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
int main()
{
	int n,i,s,r;
	char c[111];
	cin>>n;
	s=0;
	for(i=1;i<=n;i=i+1){
		cin>>c[i];
	}
	s=0;
	r=0;
	for(i=1;i<=n;i=i+1){
		if(c[i]=='1'){
			if(r>0)
				r--;
			while(r--){
				cout<<0;
			}
			r=0;
			s++;
		}
		else{
			if(s>0)
				cout<<s;
			s=0;
			r++;
		}
	}
	while(r--){
		cout<<0;
	}
	if(s>0)
		cout<<s;
	cout<<endl;
	return 0;
}