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
const int N=300005;
char s[N];
int n,cnt[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int top=cnt[1]=1;
	For(i,2,n){
		if (s[i]!=s[i-1])
			s[++top]=s[i];
		++cnt[top];
	}
	if (top%2==0) return puts("0"),0;
	For(i,1,top/2){
		if (cnt[i]+cnt[top-i+1]<3) return puts("0"),0;
		if (s[i]!=s[top-i+1]) return puts("0"),0;
	}
	if (cnt[top/2+1]<=1) return puts("0");
	printf("%d\n",cnt[top/2+1]+1);
}