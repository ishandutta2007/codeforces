#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=50050;
const int M=2*N;
int mod;
struct Matrix
{
	int a[2][2];
	Matrix(){ a[0][0]=a[1][0]=a[0][1]=a[1][1]=0;}
	void id(){ a[0][0]=a[1][1]=1;a[0][1]=a[1][0]=0;}
} r[N],l[N],t[N],my,id;
Matrix operator * (Matrix a, Matrix b)
{
	Matrix ans;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			ans.a[i][j]=0;
			for(int k=0;k<2;k++) ans.a[i][j]+=(ll)a.a[i][k]*b.a[k][j]%mod,ans.a[i][j]%=mod;
		}
	}
	return ans;
}
Matrix pow(Matrix x, ll k)
{
	Matrix ret;ret.id();
	for(;k;k>>=1,x=x*x) if(k&1) ret=ret*x;
	return ret;
}
ll pos=1,k;
int n;
Matrix node[M];
int ls[M],rs[M],tsz,root;
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ node[c]=t[ss%n];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]*node[rs[c]];
}
Matrix Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || ss>qe || qs>se) return id;
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)*Get(rs[c],mid+1,se,qs,qe);
}
void Move(ll nxt)
{
	if(nxt<=pos) return;
	//printf("Move %lld -> %lld\n",pos,nxt);
	ll L=(pos-1)/n;
	ll R=(nxt-1)/n;
	if(L==R) my=my*Get(root,1,n,(pos+1)%n==0?n:(pos+1)%n,nxt%n==0?n:nxt%n),pos=nxt;//while(pos<nxt) pos++,my=my*t[pos%n];
	else
	{
		ll sz=n+1-(pos%n==0?n:pos%n);
		my=my*r[sz];pos+=sz;
		sz=R-L-1;
		my=my*pow(l[n],sz);
		pos+=sz*n;
		sz=nxt-pos;
		my=my*l[sz];
		pos+=sz;
	}
	//printf("%i %i\n",my.a[0][0],my.a[0][1]);
	//printf("%i %i\n",my.a[1][0],my.a[1][1]);
}
void Move(int b, int a)
{
	pos++;
	Matrix tmp;
	tmp.a[0][0]=a;
	tmp.a[1][0]=b;
	tmp.a[0][1]=1;
	tmp.a[1][1]=0;
	my=my*tmp;
	//printf("Move(%i %i) %lld -> %lld\n",a,b,pos-1,pos);
	//printf("%i %i\n",my.a[0][0],my.a[0][1]);
	//printf("%i %i\n",my.a[1][0],my.a[1][1]);
}
map<ll,int> val;
int a[N],f[N];
int main()
{
	int m,i;id.id();
	scanf("%lld %i",&k,&mod);
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	vector<pair<ll,int> > work;
	scanf("%i",&m);work.resize(m);
	for(i=0;i<m;i++) scanf("%lld %i",&work[i].first,&work[i].second),val[work[i].first]=work[i].second;
	sort(work.begin(),work.end());
	while(work.size() && work.back().first>k) work.pop_back();
	if(k==0) return 0*printf("0\n");
	l[0].id();r[0].id();
	for(i=1;i<=n;i++)
	{
		Matrix tmp;
		tmp.a[0][0]=a[(i-1)%n];
		tmp.a[1][0]=a[(i-2+n)%n];
		tmp.a[0][1]=1;
		tmp.a[1][1]=0;
		t[i%n]=tmp;
		//l[i]=l[i-1]*tmp;
	}
	for(i=1;i<=n;i++) l[i]=l[i-1]*t[(i+1)%n];
	for(i=n;i>=1;i--)
	{
		/*Matrix tmp;
		tmp.a[0][0]=a[(i-1)%n];
		tmp.a[1][0]=a[(i-2+n)%n];
		tmp.a[0][1]=1;
		tmp.a[1][1]=0;*/
		r[n-i+1]=t[(i+1)%n]*r[n-i];
	}
	Build(root,1,n);
	my.id();
	for(auto p:work)
	{
		Move(p.first);
		if(pos==k) break;
		if(pos==p.first+1) Move(val[p.first],val[p.first+1]?val[p.first+1]:a[(p.first+1)%n]);
		else
		{
			Move(val[p.first-1]?val[p.first-1]:a[(p.first-1)%n],val[p.first]);
			if(pos==k) break;
			Move(val[p.first],val[p.first+1]?val[p.first+1]:a[(p.first+1)%n]);
		}
	}
	Move(k);
	printf("%i\n",my.a[0][0]%mod);
	/*printf("%i %i\n",my.a[0][0],my.a[0][1]);
	printf("%i %i\n",my.a[1][0],my.a[1][1]);
	f[1]=1;
	my.id();pos=1;
	for(i=2;i<=k;i++)
	{
		int x=val[i-2];
		if(!x) x=a[(i-2)%n];
		int y=val[i-1];
		if(!y) y=a[(i-1)%n];
		f[i]=f[i-1]*y+f[i-2]*x;
		f[i]%=mod;
		Move(x,y);
	}
	for(i=0;i<=k;i++) printf("F[%i]=%i\n",i,f[i]);
	printf("%i %i\n",my.a[0][0],my.a[0][1]);
	printf("%i %i\n",my.a[1][0],my.a[1][1]);
	printf("\n\n");
	printf("%i %i\n",l[n].a[0][0],l[n].a[0][1]);
	printf("%i %i\n",l[n].a[1][0],l[n].a[1][1]);*/
	return 0;
}