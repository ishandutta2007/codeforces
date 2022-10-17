#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=5e5+5;
int q;
long long c1[30],c2[30];
char s[N];
void solve(){
	q=in();
	for(int i=0;i<26;i++)c1[i]=c2[i]=0;
	c1[0]=c2[0]=1;
	long long len=1;
	while(q--){
		int d,k;
		scanf("%d %d %s",&d,&k,s+1);
		long long n=strlen(s+1);
		for(int i=1;i<=n;i++){
			if(d==1)c1[s[i]-'a']+=k,len+=k;
			else c2[s[i]-'a']+=k;
		}
		int mn=-1,mx=-1;
		for(int i=0;i<26;i++){
			if(c1[i]&&mn==-1)mn=i;
			if(c2[i])mx=i;
		}
		if(mn<mx||(mn==mx&&c1[mn]==len&&c1[mn]<c2[mx]))puts("YES");
		else puts("NO");
	}
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}