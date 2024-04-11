#include"bits/stdc++.h"
#define F(i,l,r) for(register int i=l;i<=r;i++)
using namespace std;
const int N=200005;
char s[N];int n,mx,mn,L,ans;
int main(){
	scanf("%d",&n);scanf("%s",s);
	L=strlen(s);int pos=0;
	while(s[pos]=='<')ans++,pos++;
	pos=L-1;while(s[pos]=='>')ans++,pos--;
	cout<<ans<<endl;
	return 0;
}