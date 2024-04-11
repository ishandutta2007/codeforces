#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 5e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,i,j,cnt,nxt[N];
char s[N],t[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%s\n%s",s+1,t+1);
	
	n = strlen(t+1);
	nxt[1]=0, j=0;
	rep(i,2,n){
		while(j&&t[j+1]!=t[i]) j=nxt[j];
		j+=t[j+1]==t[i];nxt[i]=j;
	}
	//rep(i,1,n)cout<<i<<" "<<nxt[i]<<endl;
	
	m = strlen(s+1);
	rep(i,1,m)cnt+=(s[i]=='1');
	
	j = 1;
	for(;m;--m){
		char ch = t[j];
		if(t[j]=='1'&&cnt){
			cnt--;
			printf("1");
		}else if(t[j]=='0'&&cnt<m){
			printf("0");
		}else if(!cnt){
			printf("0");
		}else printf("1");
		j = (j==n ? nxt[n] : j) + 1;
		//cout<<j<<endl;
	}
	return 0;
}