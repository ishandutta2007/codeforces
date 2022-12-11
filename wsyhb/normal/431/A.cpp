#include<bits/stdc++.h>
using namespace std;
int a[5];
char s[100005];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,ans=0,i,ss;
	char x;
	for(i=1;i<=4;i++) cin>>a[i];
	scanf("%s",s);
	ss=strlen(s);
	for(i=0;i<ss;i++)
		if(s[i]>='1'&&s[i]<='4') ans+=a[s[i]-'0'];
	cout<<ans;
	return 0;
}