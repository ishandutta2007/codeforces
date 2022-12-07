#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
void query(int *fl,int *co){
	printf("next");
	For(i,0,9) if (fl[i]) printf(" %d",i);
	puts("");
	fflush(stdout);
	int cnt;
	char s[15];
	scanf("%d",&cnt);
	For(i,1,cnt){
		scanf("%s",s+1);
		int len=strlen(s+1);
		For(j,1,len) co[s[j]-'0']=i;
	}
}
int fl[15],co[15];
void solve(){
	int tt=0;
	for (;;){
		fl[0]=fl[1]=1; tt+=2;
		query(fl,co); fl[1]=0;
		query(fl,co); fl[0]=0;
		if (co[0]==co[1]) break;
	}
	for (;;){
		For(i,0,9) fl[i]=1; tt++;
		query(fl,co);
		For(i,0,9) fl[i]=0;
		if (co[0]==co[2]) break;
	}
	puts("done");
	fflush(stdout);
}
int main(){
	solve();
}