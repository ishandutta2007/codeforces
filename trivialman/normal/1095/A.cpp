#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	string s,s1="";
	cin>>s;
	int j=0,i=0;
	while(j<n){
		s1+=s[j];
		++i; j+=i;
	}
	cout<<s1<<endl;
	return 0;
}