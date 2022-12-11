#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[100005];
ll c[26],cc[26][26];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<26;++j)cc[j][s[i]-'a']+=c[j];
		c[s[i]-'a']++;
	}
	for(int j=0;j<26;++j)ans=max(ans,c[j]);
	for(int i=0;i<26;++i)
		for(int j=0;j<26;++j)ans=max(ans,cc[i][j]);
	cout<<ans<<endl;
}