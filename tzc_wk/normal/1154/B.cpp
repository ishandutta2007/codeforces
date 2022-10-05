#include <bits/stdc++.h>
using namespace std;
int n,a[101];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)	scanf("%d",&a[i]);
	sort(a,a+n);
	vector<int> s;
	map<int,bool> u;
	for(int i=0;i<n;i++){
		if(!u[a[i]])	s.push_back(a[i]),u[a[i]]=1;
	}
	if(s.size()>3)	puts("-1");
	else if(s.size()==3){
		if(s[2]-s[1]!=s[1]-s[0])	puts("-1");
		else	printf("%d\n",s[2]-s[1]);
	}
	else if(s.size()==2){
		if((s[1]-s[0])%2==0)	printf("%d\n",(s[1]-s[0])/2);
		else	printf("%d\n",s[1]-s[0]);
	}
	else	printf("%d\n",0);
}