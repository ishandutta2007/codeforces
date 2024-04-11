#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
			ans+=s[i]%2==1;
		if(s[i]>='a'&&s[i]<='z')
			ans+=s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u';
	}
	printf("%d\n",ans);
	return 0;
}