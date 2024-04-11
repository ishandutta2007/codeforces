#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,k;
char s[N];
int main(){
	scanf("%i%i",&n,&k);
	scanf("%s",s);
	string x="";
	int mx=0;
	for(int i=1;i<n;i++){
		x+=s[i-1];
		string y="";
		for(int j=0;j<i;j++)y+=s[n-j-1];
		string tmp=y;reverse(tmp.begin(),tmp.end());
		if(x==tmp)mx=i;
	}
	printf("%s",s);
	for(int i=1;i<k;i++){
		for(int j=mx;j<n;j++)printf("%c",s[j]);
	}
	return 0;
}