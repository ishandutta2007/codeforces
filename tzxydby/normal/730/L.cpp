#include<bits/stdc++.h>
using namespace std;
int rd()
{
	char c=getchar();int x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
const int N=500005,mod=1e9+7;
char s[N];
int n,m,q,tp,x=-1,las;
int tr[N<<2],ans[N],pc[N],pr[N],sf[N],ps[N],lp[N],rp[N],val[N],b[N],lb[N],rb[N],sc[N],pw[N],ql[N],qr[N],st[N],rm[N][19];
struct sg
{
	int l,r,d;
	bool operator<(const sg k)const
	{
		if(r-l!=k.r-k.l)
			return r-l>k.r-k.l;
		else
			return d<k.d;		
	}
};
vector<sg>v;
struct nd
{
	int l,r,v;
	vector<int>s,q;
}a[N];
void pd(int k)
{
	if(tr[k])
	{
		tr[k<<1]=tr[k];
		tr[k<<1|1]=tr[k];
		tr[k]=0;
	}
}
void upd(int k,int l,int r,int a,int b,int v)
{
	if(a>b)
		return;
	if(l==a&&r==b)
	{
		tr[k]=v;
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) upd(k<<1,l,mid,a,b,v);
	else if(a>mid) upd(k<<1|1,mid+1,r,a,b,v);
	else upd(k<<1,l,mid,a,mid,v),upd(k<<1|1,mid+1,r,mid+1,b,v);
}
int ask(int k,int l,int r,int x)
{
	if(l==r)
		return tr[k];
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)	return ask(k<<1,l,mid,x);
	else return ask(k<<1|1,mid+1,r,x);
}
inline int getv(int l,int r)
{
	int ans=pc[r];
	ans=(ans+mod-1ll*pc[l-1]*pw[r-l+1]%mod)%mod;
	return ans;
}
int rmq(int l,int r)
{
	int ans=1;
	for(int i=18;i>=0;i--)
	{
		if(l+(1<<i)-1<=r)
		{
			ans=1ll*ans*rm[l][i]%mod;
			l+=(1<<i);
		}
	}
	return ans;
}
void cal(int u)
{
	if(!a[u].s.size())
		return;
	sort(a[u].s.begin(),a[u].s.end(),[&](int u,int v){return a[u].l<a[v].l;});
	int k=a[u].s.size(),kb;
	for(int i=0;i<k;i++)
	{
		int v=a[u].s[i];
		cal(v);
	}
	for(int i=0;i<k;i++)
	{
		int v=a[u].s[i];
		lp[i]=a[v].l,rp[i]=a[v].r;
		val[i]=a[v].v;
	}
	b[0]=0;
	for(int i=1;i<k;i++)
	{
		b[i]=b[i-1];
		int v=a[u].s[i];
		if(s[a[v].l-1]=='+')
			b[i]++;
	}
	kb=b[k-1];
	pr[0]=val[0];
	for(int i=1;i<k;i++)
	{
		if(b[i]==b[i-1])
			pr[i]=1ll*pr[i-1]*val[i]%mod;
		else
			pr[i]=val[i];
	}
	sf[k-1]=val[k-1];
	for(int i=k-2;i>=0;i--)
	{
		if(b[i]==b[i+1])
			sf[i]=1ll*sf[i+1]*val[i]%mod;
		else
			sf[i]=val[i];
	}
	for(int i=0;i<k;i++)
		rb[b[i]]=i;
	for(int i=k-1;i>=0;i--)
		lb[b[i]]=i;
	ps[0]=pr[rb[0]];
	for(int i=1;i<=kb;i++)
		ps[i]=(ps[i-1]+pr[rb[i]])%mod;
	a[u].v=ps[kb];
	for(int i=0;i<k;i++)
		rm[i][0]=val[i];
	for(int j=1;(1<<j)<=k;j++)
		for(int i=0;i+(1<<j)<=k;i++)
			rm[i][j]=1ll*rm[i][j-1]*rm[i+(1<<(j-1))][j-1]%mod;
	lp[k]=rp[k]=a[u].r+1;
	for(auto d:a[u].q)
	{
		int dl=ql[d],dr=qr[d],p,sum=0,bl,br,ml=1,mr=1;
		p=lower_bound(lp,lp+k+1,dl)-lp;
		if(lp[p]==dl)
			bl=p;
		else
		{
			if((lp[p]-2>=0?sc[lp[p]-2]:0)-(dl?sc[dl-1]:0))
			{
				ans[d]=-1;
				continue;
			}
			if(s[lp[p]-1]=='+')
			{
				sum=(sum+getv(dl,lp[p]-2))%mod;
				bl=p;
			}
			else
			{
				ml=getv(dl,lp[p]-2);
				bl=p;
			}
		}
		p=upper_bound(rp,rp+k+1,dr)-rp-1;
		if(p<0)
		{
			ans[d]=-1;
			continue;
		}
		if(rp[p]==dr)
			br=p;
		else
		{
			if(sc[dr]-sc[rp[p]+1])
			{
				ans[d]=-1;
				continue;
			}
			if(s[rp[p]+1]=='+')
			{
				sum=(sum+getv(rp[p]+2,dr))%mod;
				br=p;
			}
			else
			{
				mr=getv(rp[p]+2,dr);
				br=p;
			}
		}
		if(bl>br)
			ans[d]=(s[rp[p]+1]=='+'?sum:1ll*ml*mr%mod);
		else if(b[bl]==b[br])
		{
			ans[d]=rmq(bl,br);
			ans[d]=1ll*ans[d]*ml%mod*mr%mod;
			ans[d]=(ans[d]+sum)%mod;
		}
		else
		{
			ans[d]=sum;
			ans[d]=(ans[d]+1ll*sf[bl]*ml%mod)%mod;
			ans[d]=(ans[d]+1ll*pr[br]*mr%mod)%mod;
			bl=b[bl],br=b[br];
			bl++,br--;
			if(bl<=br)
			{
				int sy=(ps[br]-(bl?ps[bl-1]:0)+mod)%mod;
				ans[d]=(ans[d]+sy)%mod;
			}
		}
	}
}
int main()
{
	scanf("%s",s+1);
	scanf("%d",&q);
	m=strlen(s+1);
	n=1;
	a[1]={1,m,0};
	v.push_back({1,m,1});
	for(int i=1;i<=m;i++)
	{
		if(x!=-1&&(s[i]<'0'||s[i]>'9'))
		{
			n++;
			a[n]={las,i-1,x};
			v.push_back({las,i-1,n});
			x=-1;
		}
		if(s[i]>='0'&&s[i]<='9')
		{
			if(x==-1)
			{
				x=s[i]-'0';
				las=i;
			}
			else
				x=(10ll*x+s[i]-'0')%mod;
		}
		if(s[i]=='(')
		{
			tp++;
			st[tp]=i;
		}
		if(s[i]==')')
		{
			n++;
			a[n]={st[tp],i,0};
			v.push_back({st[tp],i,n});
			tp--;
		}
	}
	if(x!=-1)
	{
		n++;
		a[n]={las,m,x};
		v.push_back({las,m,n});
		x=-1;
	}
	pw[0]=1;
	for(int i=1;i<=m;i++)
		pw[i]=10ll*pw[i-1]%mod;
	for(int i=1;i<=m;i++)
		if(s[i]>='0'&&s[i]<='9')
			pc[i]=(10ll*pc[i-1]+s[i]-'0')%mod;
	for(int i=1;i<=m;i++)
		sc[i]=sc[i-1]+(s[i]=='('||s[i]==')'||s[i]=='+'||s[i]=='*');
	for(int i=1;i<=q;i++)
	{
		ql[i]=rd(),qr[i]=rd();
		if(s[ql[i]]=='+'||s[ql[i]]=='*'||s[qr[i]]=='+'||s[qr[i]]=='*'||s[ql[i]]==')'||s[qr[i]]=='(')
		{
			ans[i]=-1;
			continue;
		}
		if(sc[qr[i]]-sc[ql[i]-1]==0)
		{
			ans[i]=getv(ql[i],qr[i]);
			continue;	
		}
		v.push_back({ql[i],qr[i],-i});
	}
	sort(v.begin(),v.end());
	upd(1,1,m,1,m,1);
	for(auto x:v)
	{
		if(x.d>0)
		{
			if(x.d!=1)
			{
				int f=ask(1,1,m,x.l);
				a[f].s.push_back(x.d);
			}
			if(!a[x.d].v)
				upd(1,1,m,x.l+1,x.r-1,x.d);
		}
		else
		{
			x.d=-x.d;
			int fl=ask(1,1,m,x.l),fr=ask(1,1,m,x.r);
			if(fl!=fr)
				ans[x.d]=-1;
			else
				a[fl].q.push_back(x.d);
		}
	}
	cal(1);
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}