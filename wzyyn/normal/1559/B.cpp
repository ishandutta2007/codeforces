#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n;
char s[105];
void construct(int l,int r){
	if (s[l-1]=='B'||s[l-1]=='R'){
		for (int i=l;i<=r;i++)
			s[i]='B'+'R'-s[i-1];
	}
	else if (s[r+1]=='B'||s[r+1]=='R'){
		for (int i=r;i>=l;i--)
			s[i]='B'+'R'-s[i+1];
	}
	else{
		for (int i=l;i<=r;i++)
			s[i]=(i&1?'B':'R');
	}
}
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int la=1;
	for (int i=1;i<=n;i++)
		if (s[i]=='B'||s[i]=='R')
			construct(la,i-1),la=i+1;
	construct(la,n);
	printf("%s\n",s+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}