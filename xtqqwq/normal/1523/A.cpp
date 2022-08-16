#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
char s[1005],t[1005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		chkmin(m,n);
		scanf("%s",s+1);
		s[0]=s[n+1]=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++) t[j]='0';
			t[0]=t[n+1]=0;
			for(int j=1;j<=n;j++){
				if(s[j]=='1') t[j]='1';
				else if((s[j-1]=='1')^(s[j+1]=='1')) t[j]='1';
			}
			swap(s,t);
		}
		puts(s+1);
	}
	return 0;
}