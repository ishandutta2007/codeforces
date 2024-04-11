#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,Q,ans;
char s[N],t[5];
bool chk(int x){
	return s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c';
}
int main(){
	scanf("%d%d",&n,&Q);
	scanf("%s",s+1);
	for (int i=1;i+2<=n;i++) ans+=chk(i);
	while (Q--){
		int x;
		scanf("%d%s",&x,t+1);
		if (1<=x&&x<=n-2) ans-=chk(x);
		if (1<=x-1&&x-1<=n-2) ans-=chk(x-1);
		if (1<=x-2&&x-2<=n-2) ans-=chk(x-2);
		s[x]=t[1];
		if (1<=x&&x<=n-2) ans+=chk(x);
		if (1<=x-1&&x-1<=n-2) ans+=chk(x-1);
		if (1<=x-2&&x-2<=n-2) ans+=chk(x-2);
		printf("%d\n",ans); 
	}
}