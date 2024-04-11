#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s,t;
int main(){
	map<string,int>mp;
	mp["monday"]=0,mp["tuesday"]=1,mp["wednesday"]=2,mp["thursday"]=3;
	mp["friday"]=4,mp["saturday"]=5,mp["sunday"]=6;
	cin>>s>>t;
	int a=mp[s],b=mp[t];
	if(a==b||(a+3)%7==b||(a+2)%7==b)
		puts("YES");
	else puts("NO");
	return 0;
}