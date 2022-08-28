//CF 832B
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
char c[333],s[111111],q[111111];
int f[333];
int main()
{
	int n,i,j,l,p,ans;
	scanf("%s",&c);
	l=strlen(c);
	for(i=0;i<l;i=i+1)
		f[c[i]]=1;
	scanf("%s",&s);
	l=strlen(s);
	j=-1;
	for(i=0;i<l;i=i+1)
		if(s[i]=='*')
			j=i;
	scanf("%d",&n);
	while(n--){
		scanf("%s",&q);
		p=strlen(q);
		ans=1;
		if(j==-1){
			if(p!=l){
				cout<<"NO\n";
				continue;
			}
			for(i=0;i<p;i=i+1){
				if(s[i]!='?'&&s[i]!=q[i])
					ans=0;
				if(s[i]=='?'&&!f[q[i]])
					ans=0;
			}
		}
		else{
			if(p<l-1){
				cout<<"NO\n";
				continue;
			}
			for(i=0;i<j;i=i+1){
				if(s[i]!='?'&&s[i]!=q[i])
					ans=0;
				if(s[i]=='?'&&!f[q[i]])
					ans=0;
			}
			for(i=l-1;i>j;i=i-1){
				if(s[i]!='?'&&s[i]!=q[p-l+i])
					ans=0;
				if(s[i]=='?'&&!f[q[p-l+i]])
					ans=0;
			}
			for(i=j;i<=p-l+j;i=i+1)
				if(f[q[i]])
					ans=0;
		}
		if(ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}