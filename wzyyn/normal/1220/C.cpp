#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
char s[500005];
int main(){
	scanf("%s",s+1);
	char mn='z'+1;
	int n=strlen(s+1);
	For(i,1,n){
		puts(s[i]>mn?"Ann":"Mike");
		mn=min(mn,s[i]);
	}
}