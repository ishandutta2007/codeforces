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
const int mo=998244353;
const int N=5005;
int fa[N],v[N],fav[N];
int ans,flag,m,spe[N];
char s[N];
int get(int x){
	if (x==fa[x]) return fa[x];
	int y=fa[x];
	fa[x]=get(fa[x]);
	v[x]=v[y]^fav[x];
	fav[x]=v[x]^v[fa[x]];
	return fa[x];
}
void merge(int x,int y,int v){
	int X=get(x),Y=get(y);
	if (X==Y){
		if (fav[x]^fav[y]^v)
			flag=0;
	}
	else{
		fa[Y]=X;
		fav[Y]=fav[x]^fav[y]^v;
	}
}
void calc(int l1,int l2){
	flag=1;
	For(i,1,l1+l2) fa[i]=i,fav[i]=v[i]=0;
	for (int p1=1,p2=l1;p1<p2;p1++,p2--) merge(p1,p2,0);
	for (int p1=1,p2=l2;p1<p2;p1++,p2--) merge(l1+p1,l1+p2,0);
	For(i,1,l1) if (s[i]!='?') merge(i,i+l1,s[i]-'0');
	For(i,1,l1+l2) spe[i]=-1;
	int cnt=0;
	For(i,1,l1+l2){
		spe[i]=-1;
		if (fa[i]==i) ++cnt;
	}
	For(i,l1+1,l2) if (s[i]!='?'){
		get(i+l1);
		int val=(s[i]-'0')^v[i+l1];
		if (spe[fa[i+l1]]==-1)
			spe[fa[i+l1]]=val,--cnt;
		else if (spe[fa[i+l1]]!=val)
			flag=0;
	}
	get(l1);
	int val=v[l1]^1;
	if (spe[fa[l1]]==-1)
		spe[fa[l1]]=val,--cnt;
	else if (spe[fa[l1]]!=val)
		flag=0;
	if (!flag) return;
	int sum=1;
	For(i,1,cnt)
		sum=sum*2%mo;
	ans=(ans+sum)%mo;
}
int main(){
	scanf("%s",s+1);
	m=strlen(s+1);
	For(i,1,m-1) calc(i,m);
	printf("%d\n",ans);
}