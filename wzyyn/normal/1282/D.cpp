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
char s[505];
int main(){
	int sa=0,sb=0,na=0,nb=0;
	For(i,1,300) cout<<'a'; cout<<endl;
	scanf("%d",&sa);
	if (!sa) return 0;
	sa=300-sa;
	
	For(i,1,300) cout<<'b'; cout<<endl;
	scanf("%d",&sb);
	if (!sb) return 0;
	sb=300-sb;
	
	For(i,1,sa+sb)
		if (nb==sb) s[i]='a',++na;
		else{
			s[i]='b';
			For(j,na+1,sa) s[i+j-na]='a';
			printf("%s",s+1); cout<<endl;
			int v;
			scanf("%d",&v);
			if (!v) return 0;
			if (v==sb-nb-1) ++nb;
			else s[i]='a',++na;
		}
	printf("%s\n",s+1);
}