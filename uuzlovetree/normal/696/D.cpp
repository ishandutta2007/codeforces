#include<bits/stdc++.h>
#define maxn 205
using namespace std;
typedef long long ll;
int n;
ll a[maxn],l;
char s[maxn];
struct ACAM
{ 
	int ch[maxn][26],fail[maxn],cnt;
	ll val[maxn];
	queue<int> q;
	stack<int> stk;
	void ins(char *s,ll v)
	{
	    int now=0,len=strlen(s);
	    for(int i=0;i<len;i++)
	    {
	        if(!ch[now][s[i]-'a'])ch[now][s[i]-'a']=++cnt;
	        now=ch[now][s[i]-'a'];
	    }
	    val[now]+=v;
	}
	void ACbuild()
	{
	    for(int i=0;i<26;i++)if(ch[0][i])fail[ch[0][i]]=0,q.push(ch[0][i]);
	    while(!q.empty())
	    {
	        int now=q.front();q.pop();
	        for(int i=0;i<26;i++)
	        if(ch[now][i])fail[ch[now][i]]=ch[fail[now]][i],q.push(ch[now][i]);
	        else ch[now][i]=ch[fail[now]][i];
	        val[now]+=val[fail[now]];
	        stk.push(now);
	    }
	}
}acam;
const ll inf = (ll)1e18;
int N;
struct Matrix
{
	ll m[maxn][maxn];
	void clear()
	{
		for(int i=0;i<=N;++i)
			for(int j=0;j<=N;++j)m[i][j]=-inf; 
	}
	void init()
	{
		for(int i=0;i<=N;++i)
			for(int j=0;j<=N;++j)m[i][j]=-inf; 
		m[0][0]=0;
	}
};
Matrix operator * (const Matrix &A,const Matrix &B)
{
	Matrix C;C.clear();
	for(int k=0;k<=N;++k)
		for(int i=0;i<=N;++i)
			for(int j=0;j<=N;++j)C.m[i][j]=max(C.m[i][j],A.m[i][k]+B.m[k][j]);
	return C;
}
Matrix fastpow(Matrix a,ll p)
{
	Matrix ans;
	ans.init();
	while(p)
	{
		if(p&1)ans=ans*a;
		a=a*a;p>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%lld",&n,&l);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		acam.ins(s,a[i]);
	}
	acam.ACbuild();
	Matrix A;
	N=acam.cnt;
	A.clear();
	for(int i=0;i<=N;++i)
	{
		for(int j=0;j<26;++j)
		{
			int t=acam.ch[i][j];
			A.m[i][t]=max(A.m[i][t],acam.val[t]);
		}
	}
	A=fastpow(A,l);
	ll ans=0;
	for(int i=0;i<=N;++i)ans=max(ans,A.m[0][i]);
	printf("%lld\n",ans);
}