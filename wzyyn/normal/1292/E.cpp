#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int n;
char ans[55];
char tmp[55];
int query(char *s){
	int l=strlen(s);
	printf("? %s\n",s);
	fflush(stdout);
	int t;
	scanf("%d",&t);
	assert(t!=-1);
	//cout<<l<<endl;
	For(i,1,t){
		int x;
		scanf("%d",&x);
		For(j,0,l-1)
			ans[x+j]=s[j];
	}
	return t;
}
void FF(char x){
	For(i,1,n) if (ans[i]=='.') ans[i]=x;
}
void CF(char c1,char c2){
	memcpy(tmp,ans,sizeof(tmp));
	For(i,1,n) if (tmp[i]=='.') tmp[i]=c1;
	FF(query(tmp+1)?c1:c2);
}
void answer(){
	printf("! %s\n",ans+1);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	assert(x);
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) ans[i]='.'; ans[n+1]=0;
	int v=query("OC")+query("CO")+query("OH")+query("CH");
	if (!v){
		if (query("CCC")) return FF('H'),answer();
		if (query("OOO")) return FF('H'),answer();
		if (query("HHH")) return CF('O','C'),answer();
		ans[1]=ans[2]='H';
		return CF('O','C'),answer();
	}
	else if (n==4&&ans[1]=='.'&&ans[4]=='.'&&ans[3]=='H'&&(ans[2]=='C'||ans[2]=='O')){
		ans[4]=0; ans[1]=ans[2];
		if (!query(ans+1)) ans[1]='H';
		ans[4]='H';
		if (!query(ans+1)){
			ans[4]='C';
			if (!query(ans+1))
				ans[4]='O';
		}
		return answer();
	}
	else{
		query("HH");
		For(i,1,n) if (ans[i]=='.'){
			char a1=0,a2=0;
			For(j,1,i-1) if (ans[j]!='.') a1=ans[j];
			Rep(j,n,i+1) if (ans[j]!='.') a2=ans[j];
			ans[i]=(a1=='H'||a1==0?a2:a1);
			if (!ans[i]||i==1) ans[i]='.';
		}
		//printf("%s\n",ans+1);
		int p1=1,p2=n;
		for (;ans[p1]=='.';++p1);
		for (;ans[p2]=='.';--p2);
		if (p1!=1) For(i,1,p1-1) ans[i]='H';
		if (p2!=n) For(i,p2+1,n) ans[i]='C';
		if (query(ans+1)) return answer();
		if (p2!=n){
			For(i,p2+1,n) ans[i]='O';
			if (query(ans+1)) return answer();
		}
		if (p1!=1){
			For(i,1,p1-1) ans[1]=ans[p1];
			if (p2!=n) For(i,p2+1,n) ans[i]='C';
			if (query(ans+1)) return answer();
			For(i,p2+1,n) ans[i]='O';
			return answer();
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
OC CO
OH CH

OC,CO,OH,CH:
	H+(O/C)
	CCC
	OOO
	HHH
	
	1+3/9+1/16

	
		OO,CC,O*,C*
		HO,HCHH
		*O,*C,H*
			4.OH.,.CH.
			
..OH.
.OOH.
*/