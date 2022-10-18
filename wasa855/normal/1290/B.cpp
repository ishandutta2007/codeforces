#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
char s[N];
#define ls (u<<1)
#define rs (u<<1|1)
bitset<30> t[N*4];
void build(int u,int l,int r)
{
	if(l==r)
	{
		t[u].set(s[l]-'a'+1);
		return ;
	}
	int mid=(l+r)/2;
	build(ls,l,mid),build(rs,mid+1,r);
	t[u]=t[ls]|t[rs];
}
bitset<30> query(int u,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return t[u];
	int mid=(l+r)/2;
	bitset<30> ans;ans.reset();
	if(mid>=L) ans|=query(ls,l,mid,L,R);
	if(mid<R) ans|=query(rs,mid+1,r,L,R);
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",s+1);
	int n=strlen(s+1);
	build(1,1,n);;
	int q=read();
	while(q--)
	{
		int l=read(),r=read();
		if(l==r) 
		{
			printf("Yes\n");
			continue;
		}
		bitset<30> ans=query(1,1,n,l,r);
		int res=0;
		for(int i=1;i<=26;i++)
		{
			if(ans[i]) res++;
		}
//		cout<<res<<endl;
		if(res==1) printf("No\n");
		else if(res==2)
		{
			if(s[l]==s[r]) printf("No\n");
			else printf("Yes\n");
		}
		else printf("Yes\n");
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}