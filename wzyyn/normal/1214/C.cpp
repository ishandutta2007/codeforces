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
int n;
char s[200005];
int main(){
	scanf("%d%s",&n,s+1);
	int len=strlen(s+1);
	int S=0,mn=0;
	For(i,1,n){
		S+=(s[i]=='('?1:-1);
		mn=min(mn,S);
	}
	puts(S==0&&mn>=-1?"Yes":"No");
}