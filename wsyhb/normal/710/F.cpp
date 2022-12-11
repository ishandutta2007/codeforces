#include<bits/stdc++.h>
using namespace std;
const int P[3]={998244353,int(1e9+7),int(1e9+9)};
const int max_len=3e5+5;
struct Hash
{
	int len,v[3];
	inline Hash(int x=0)
	{
		len=v[0]=v[1]=v[2]=x;
	}
}power[max_len],pre[max_len];
inline void init()
{
	power[0]=Hash(1);
	for(int i=1;i<=3e5;++i)
	{
		power[i].len=1;
		for(int j=0;j<3;++j)
			power[i].v[j]=26ll*power[i-1].v[j]%P[j];
	}
}
inline Hash operator + (const Hash &a,char x)
{
	static Hash res;
	res.len=a.len+1;
	for(int i=0;i<3;++i)
		res.v[i]=(26ll*a.v[i]+(x-'a'))%P[i];
	return res;
}
inline Hash operator - (const Hash &a,const Hash &b)
{
	static Hash res;
	res.len=a.len-b.len;
	for(int i=0;i<3;++i)
		res.v[i]=a.v[i]-b.v[i]+(a.v[i]<b.v[i]?P[i]:0);
	return res;
}
inline Hash operator * (const Hash &a,const Hash &b)
{
	static Hash res;
	res.len=a.len*b.len;
	for(int i=0;i<3;++i)
		res.v[i]=1ll*a.v[i]*b.v[i]%P[i];
	return res; 
}
inline bool operator == (const Hash &a,const Hash &b)
{
	if(a.len!=b.len)
		return false; 
	for(int i=0;i<3;++i)
	{
		if(a.v[i]!=b.v[i])
			return false;
	}
	return true;
}
inline Hash get_hash(int l,int r)
{
	return pre[r]-pre[l-1]*power[r-l+1];
}
vector<Hash> h_ins,h_del;
const int max_tot=3e5+5;
struct Trie
{
	int tr[max_tot][26],cnt[max_tot],tot;
	inline void insert(const char *s)
	{
		int cur=0;
		for(int i=0;s[i];++i)
		{
			if(!tr[cur][s[i]-'a'])
				tr[cur][s[i]-'a']=++tot;
			cur=tr[cur][s[i]-'a'];
		}
		++cnt[cur];
	}
	inline long long query(const char *s)
	{
		long long res=0;
		for(int i=0;s[i];++i)
		{
			int cur=0;
			for(int j=i;s[j];++j)
			{
				cur=tr[cur][s[j]-'a'];
				if(!cur)
					break;
				res+=cnt[cur]; 
			}
		}
		return res;
	}
}ins,del;
const int range=599;
char s[max_len];
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	init();
	int m;
	scanf("%d",&m);
//	cerr<<"m="<<m<<"\n";
	for(int k=1;k<=m;++k)
	{
		int t;
		scanf("%d%s",&t,s+1);
		int len=strlen(s+1);
//		fprintf(stderr,"t=%d len=%d\n",t,len);
		if(t==1)
		{
			if(len<=range)
				ins.insert(s+1);
			else
			{
				static Hash res;
				res=Hash(0);
				for(int i=1;i<=len;++i)
					res=res+s[i];
				h_ins.push_back(res);
			}
		}
		else if(t==2)
		{
			if(len<=range)
				del.insert(s+1);
			else
			{
				static Hash res;
				res=Hash(0);
				for(int i=1;i<=len;++i)
					res=res+s[i];
				h_del.push_back(res);
			}
		}
		else
		{
			long long ans=ins.query(s+1)-del.query(s+1);
//			cerr<<"1\n";
			for(int i=1;i<=len;++i)
				pre[i]=pre[i-1]+s[i];
//			cerr<<"2\n";
			for(int i=0;i<int(h_ins.size());++i)
			{
				int l=h_ins[i].len;
				for(int j=1;j+l-1<=len;++j)
					ans+=(get_hash(j,j+l-1)==h_ins[i]);
			}
//			cerr<<"3\n";
			for(int i=0;i<int(h_del.size());++i)
			{
				int l=h_del[i].len;
				for(int j=1;j+l-1<=len;++j)
					ans-=(get_hash(j,j+l-1)==h_del[i]);
			}
			printf("%lld\n",ans);
			fflush(stdout);
		}
	}
    return 0;
}