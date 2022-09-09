#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mt make_tuple
const int m1=998244353;
const int m2=977787779;
const int m3=950747059;
struct hsh
{
	int x,y,z;
	hsh(int a=0):x(a%m1),y(a%m2),z(a%m3){}
	hsh(int a, int b, int c):x(a),y(b),z(c){}
	hsh operator + (hsh b){ return hsh((x+b.x)%m1,(y+b.y)%m2,(z+b.z)%m3);}
	hsh operator - (hsh b){ return hsh((x-b.x+m1)%m1,(y-b.y+m2)%m2,(z-b.z+m3)%m3);}
	hsh operator * (hsh b){ return hsh((ll)x*b.x%m1,(ll)y*b.y%m2,(ll)z*b.z%m3);}
	bool operator < (hsh b) const { return mt(x,y,z)<mt(b.x,b.y,b.z);}
	bool operator == (hsh b) const { return mt(x,y,z)==mt(b.x,b.y,b.z);}
};
const int N=200050;
const int L=18;
struct EERTREE
{
	int IMAG,ZERO,tsz,go[N][26],len[N],link[N][L],at,sz,nod[N],pos[N];
	char s[N];
	void init()
	{
		tsz=sz=0;
		IMAG=++tsz;link[IMAG][0]=IMAG;len[IMAG]=-1;
		ZERO=++tsz;link[ZERO][0]=IMAG;len[ZERO]=0;
		at=IMAG;
	}
	EERTREE(){ init();}
	void Grow(char c)
	{
		s[++sz]=c;
		while(c!=s[sz-len[at]-1]) at=link[at][0];
		if(!go[at][c-'a'])
		{
			go[at][c-'a']=++tsz;
			pos[tsz]=sz;
			len[tsz]=len[at]+2;
			int suf=link[at][0];
			while(c!=s[sz-len[suf]-1]) suf=link[suf][0];
			if(len[tsz]==1) link[tsz][0]=ZERO;
			else link[tsz][0]=go[suf][c-'a'];
		}
		at=go[at][c-'a'];
		nod[sz]=at;
	}
	void Build(char s[], int n)
	{
		init();
		for(int i=1;i<=n;i++) Grow(s[i]);
		for(int j=1;j<L;j++)
			for(int i=1;i<=tsz;i++)
				link[i][j]=link[link[i][j-1]][j-1];
	}
	int Get(int u, int x)
	{
		if(len[u]<=x) return len[u];
		for(int i=L-1;~i;i--) if(len[link[u][i]]>x) u=link[u][i];
		return len[link[u][0]];
	}
	bool Check(int u, int x)
	{
		for(int i=L-1;~i;i--) if(len[link[u][i]]>=x) u=link[u][i];
		return len[u]==x;
	}
} FW[2],BW[2];
int Decompose(int t, int l, int r, int n)
{
	int pre=BW[t].Get(BW[t].nod[n-l+1],r-l+1);
	if(pre>0 && FW[t].Check(FW[t].nod[r],r-l+1-pre)) return pre;
	int suf=FW[t].Get(FW[t].nod[r],r-l+1);
	if(suf>0 && BW[t].Check(BW[t].nod[n-l+1],r-l+1-suf)) return r-l+1-suf;
	return -1;
}
char s[N],t[N];
hsh H[2][N],po[N];
hsh Get(int t, int l, int r){ return H[t][r]-H[t][l-1]*po[r-l+1];}
map<hsh,int> cnt[2];
set<hsh> st[2];
int main()
{
	int n,m;
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s",t+1);m=strlen(t+1);
	FW[0].Build(s,n);
	FW[1].Build(t,m);
	reverse(s+1,s+1+n);
	reverse(t+1,t+1+m);
	BW[0].Build(s,n);
	BW[1].Build(t,m);
	reverse(s+1,s+1+n);
	reverse(t+1,t+1+m);
	ll ans=(ll)(FW[0].tsz-2)*(FW[1].tsz-2);
	po[0]=hsh(1);
	po[1]=hsh(777);
	for(int i=2;i<N;i++) po[i]=po[i-1]*po[1];
	for(int i=1;i<=n;i++) H[0][i]=H[0][i-1]*po[1]+hsh(s[i]-'a'+1);
	for(int i=1;i<=m;i++) H[1][i]=H[1][i-1]*po[1]+hsh(t[i]-'a'+1);
	for(int t=0;t<2;t++)
	{
		for(int i=3;i<=FW[t].tsz;i++)
		{
			st[t].insert(Get(t,FW[t].pos[i]-FW[t].len[i]+1,FW[t].pos[i]));
			int border=FW[t].link[i][0],l,r;
			if(border<3) continue;
			if(t==0) l=FW[t].pos[i]-(FW[t].len[i]-FW[t].len[border])+1,r=FW[t].pos[i];
			else l=FW[t].pos[i]-FW[t].len[i]+1,r=FW[t].pos[i]-FW[t].len[border];
			if(FW[t].len[border]*2>=FW[t].len[i])
				cnt[t][Get(t,l,r)]++;
		}
	}
	for(int t=0;t<2;t++)
	{
		for(int i=3;i<=FW[t].tsz;i++)
		{
			int border=FW[t].link[i][0],l,r;
			if(border<3) continue;
			if(t==0) l=FW[t].pos[i]-(FW[t].len[i]-FW[t].len[border])+1,r=FW[t].pos[i];
			else l=FW[t].pos[i]-FW[t].len[i]+1,r=FW[t].pos[i]-FW[t].len[border];
			ans-=cnt[t^1][Get(t,l,r)];
			int pre=Decompose(t,l,r,t==0?n:m);
			if(~pre && pre!=r-l+1)
			{
				if(t==0)
				{
					if(st[t^1].count(Get(t,l,l+pre-1)) && st[t^1].count(Get(t,l,r)*po[pre]+Get(t,l,l+pre-1)))
						ans--;
				}
				else
				{
					int suf=r-l+1-pre;
					if(st[t^1].count(Get(t,r-suf+1,r)) && st[t^1].count(Get(t,r-suf+1,r)*po[r-l+1]+Get(t,l,r)))
						ans--;
				}
			}
		}
	}
	for(int t=0;t<2;t++)
	{
		for(int i=3;i<=FW[t].tsz;i++)
		{
			int border=FW[t].link[i][0],l,r;
			if(border<3) continue;
			if(t==0) l=FW[t].pos[i]-(FW[t].len[i]-FW[t].len[border])+1,r=FW[t].pos[i];
			else l=FW[t].pos[i]-FW[t].len[i]+1,r=FW[t].pos[i]-FW[t].len[border];
			if(FW[t].len[border]*2<FW[t].len[i])
				cnt[t][Get(t,l,r)]++;
		}
	}
	for(auto p:cnt[0]) ans+=(ll)p.second*cnt[1][p.first];
	printf("%lld\n",ans);
	return 0;
}