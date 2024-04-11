#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s,n=s.size();
		int flg=1;
		for(int i=1;i<n;i++)
			flg&=(s[i-1]==s[i]);
		if(flg){
			cout<<s<<"\n";
			continue;
		}
		for(int i=0;i<n;i++)
			putchar('0'),putchar('1');
		puts("");
	}
	return 0;
}