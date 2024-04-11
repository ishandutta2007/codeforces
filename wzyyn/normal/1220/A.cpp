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
int n,s0,s1;
char s[100005];
int main(){
	scanf("%d%s",&n,s+1);
	For(i,1,n)
		if (s[i]=='z') ++s0;
		else if (s[i]=='n') ++s1;
	For(i,1,s1) printf("1 ");
	For(i,1,s0) printf("0 ");
}