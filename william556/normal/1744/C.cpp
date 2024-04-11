// LUOGU_RID: 90774395
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=4e5+5;
int n;
char s[N],c;
void solve(){
	scanf("%d %c",&n,&c);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)s[i+n]=s[i];
	int lst=0,ans=0;
	for(int i=n<<1;i>=1;i--){
		if(s[i]=='g')lst=i;;
		if(s[i]==c)ans=max(ans,lst-i);
	}
	printf("%d\n",ans);
}
int main(){
//	freopen("in.txt","r",stdin);	
	int t=in();
	while(t--)solve();
	return 0;
}