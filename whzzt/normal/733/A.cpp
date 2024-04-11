#include"bits/stdc++.h"
#define F(i,l,r) for(register int i=l;i<=r;i++)
#define D(i,r,l) for(register int i=r;i>=l;i--)
using namespace std;
typedef long long ll;
char s[105];int ans,l,last;
int main(){
	scanf("%s",s+1);l=strlen(s+1);
	F(i,1,l)
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
			ans=max(ans,i-last),last=i;
	ans=max(ans,l+1-last);
	cout<<ans<<endl;
	return 0;
}