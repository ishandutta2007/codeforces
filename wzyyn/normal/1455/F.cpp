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

const int N=505;
char s[N],t[N][N];
int n,k;

void UPD(char *c1,char *c2,int l){
	For(i,1,l) if (c1[i]!=c2[i]){
		if (c1[i]<c2[i])
			For(j,i,l) c2[j]=c1[j];
		return;
	}
}
void solve(){
	scanf("%d%d%s",&n,&k,s+1);
	memset(t,125,sizeof(t));
	For(i,0,n-1){
		char c;
		if (s[i+1]=='a'+k-1) c='a';
		else c=(s[i+1]=='a'?s[i+1]:s[i+1]-1);
		t[i][i+1]=c;
		UPD(t[i],t[i+1],i+1);
		t[i][i+1]=125;
		//UD0
		
		if (i!=0){
			t[i][i+1]=s[i+1];
			swap(t[i][i+1],t[i][i]);
			UPD(t[i],t[i+1],i+1);
			swap(t[i][i+1],t[i][i]);
			t[i][i+1]=125;
		}
		//L
		
		
		if (i!=n-1){	
			if (s[i+2]=='a'+k-1) c='a';
			else c=(s[i+2]=='a'?s[i+2]:s[i+2]-1);
			t[i][i+1]=c; t[i][i+2]=s[i+1];
			UPD(t[i],t[i+2],i+2);
			//RU,RD,R0
			
			t[i][i+1]=s[i+2];
			swap(t[i][i+1],t[i][i]);
			UPD(t[i],t[i+2],i+2);
			swap(t[i][i+1],t[i][i]);
			t[i][i+1]=t[i][i+2]=125;
			//RL
		}
	}
	For(i,1,n) putchar(t[n][i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}