#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n;
int minr[N];
char s1[N], s2[N];

int check(int n, char s[]){
	int cnt = 0, minl = N, minpos = 0, ans = 0;
	rep(i,0,n-1){
		if(s[i]=='(')cnt += 1;else cnt -= 1;
		minl = min(minl, cnt);
		minr[i] = cnt;
	}
	for(int i=n-2;i>=0;--i)minr[i]=min(minr[i],minr[i+1]);
	if(cnt!=2||minl<0)
		return 0;
	else{
		rep(i,0,n-1)if(minr[i]>=2&&s[i]=='(')++ans;
		return ans;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d\n",&n);
	scanf("%s\n",&s1);
	rep(i,0,n-1)s2[n-1-i]=(s1[i]=='(')?')':'(';
	
	if(check(n, s1))cout<<check(n, s1)<<endl;
	else if(check(n, s2))cout<<check(n, s2)<<endl;
	else cout<<0<<endl;
	return 0;
}