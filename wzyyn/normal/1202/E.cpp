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
#define y1 hfjskghsdjkfg
using namespace std;
const int N=200005;
char s[N],t[N];
int ans1[N],ans2[N],n;
struct ACM{
	int ch[N][26],nd;
	int sz[N],fail[N],q[N];
	ACM(){
		nd=1;
		memset(ch,0,sizeof(ch));
	}
	void insert(char *s,int len){
		int x=1;
		For(i,1,len){
			if (!ch[x][s[i]-'a'])
				ch[x][s[i]-'a']=++nd;
			x=ch[x][s[i]-'a'];
		}
		++sz[x];
	}
	void build(){
		int h=0,t=0;
		fail[1]=1;
		For(i,0,25)
			if (ch[1][i]){
				q[++t]=ch[1][i];
				fail[ch[1][i]]=1;
			}
			else ch[1][i]=1;
		while (h!=t){
			int x=q[++h];
			sz[x]+=sz[fail[x]];
			For(i,0,25)
				if (!ch[x][i])
					ch[x][i]=ch[fail[x]][i];
				else{
					int y=fail[x];
					for (;!ch[y][i];y=fail[y]);
					fail[ch[x][i]]=ch[y][i];
					q[++t]=ch[x][i];
				}
		}
	}
	void getans(char *s,int len,int *ans){
		int x=1;
		For(i,1,len){
			x=ch[x][s[i]-'a'];
			ans[i]=sz[x];
		}
	}
}T1,T2;
int main(){
	scanf("%s%d",s+1,&n);
	For(i,1,n){
		scanf("%s",t+1);
		int len=strlen(t+1);
		T1.insert(t,len);
		reverse(t+1,t+len+1);
		T2.insert(t,len);
	}
	T1.build();
	T2.build();
	int len=strlen(s+1);
	T1.getans(s,len,ans1);
	reverse(s+1,s+len+1);
	T2.getans(s,len,ans2);
	ll ans=0;
	For(i,1,len-1) ans+=1ll*ans1[i]*ans2[len-i];
	printf("%lld\n",ans);
}