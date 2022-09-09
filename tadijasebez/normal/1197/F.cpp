#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int mod=998244353;
const ll MOD=(ll)mod*mod;
const int M=64;
const int L=30;
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
vector<int> possible;
int GetIndex(int x){ return lower_bound(possible.begin(),possible.end(),x)-possible.begin();}
struct Matrix
{
	ll a[M][M];
	void init(){ for(int i=0;i<M;i++) for(int j=0;j<M;j++) a[i][j]=0;}
	Matrix(){ init();}
	void id(){ init();for(int i=0;i<M;i++) a[i][i]=1;}
};
Matrix operator * (Matrix a, Matrix b)
{
	Matrix ans;
	for(int i=0;i<possible.size();++i)
	{
		for(int j=0;j<possible.size();++j)
		{
			for(int k=0;k<possible.size();++k)
			{
				//ans.a[i][j]=add(ans.a[i][j],mul(a.a[i][k],b.a[k][j]));
				ans.a[i][j]+=a.a[i][k]*b.a[k][j];
				if(ans.a[i][j]>=MOD) ans.a[i][j]-=MOD;
			}
			ans.a[i][j]%=mod;
		}
	}
	return ans;
}
Matrix po[L];
Matrix pow(int k)
{
	Matrix ans;
	ans.id();
	for(int z=0;z<L;++z) if(k>>z&1)
	{
		Matrix tmp;
		for(int i=0;i<possible.size();++i)
		{
			for(int j=0;j<possible.size();++j)
			{
				for(int k=0;k<possible.size();++k)
				{
					tmp.a[i][j]+=ans.a[i][k]*po[z].a[k][j];
					if(tmp.a[i][j]>=MOD) tmp.a[i][j]-=MOD;
				}
				tmp.a[i][j]%=mod;
			}
		}
		ans=tmp;
	}
	return ans;
	/*Matrix ans;
	ans.id();
	for(;k;k>>=1)
	{
		if(k&1)
		{
			Matrix tmp;
			for(int i=0;i<M;++i)
			{
				for(int j=0;j<M;++j)
				{
					for(int k=0;k<M;++k)
					{
						//ans.a[i][j]=add(ans.a[i][j],mul(a.a[i][k],b.a[k][j]));
						tmp.a[i][j]+=a.a[i][k]*b.a[k][j];
						if(ans.a[i][j]>=MOD) ans.a[i][j]-=MOD;
					}
					tmp.a[i][j]%=mod;
				}
			}
		}
	}*/
	/*Matrix ans;
	ans.id();
	for(;k;k>>=1,x=x*x) if(k&1) ans=ans*x;
	return ans;*/
}
struct Vector
{
    int v[M];
    void init(){ for(int i=0;i<M;i++) v[i]=0;}
    Vector(){ init();}
};
Vector operator * (Vector a, Matrix b)
{
	Vector ans;
	for(int i=0;i<possible.size();i++)
	{
		ans.v[i]=0;
		for(int j=0;j<possible.size();j++)
		{
			ans.v[i]=add(ans.v[i],mul(a.v[j],b.a[j][i]));
		}
	}
	return ans;
}
Matrix match[4];
int can[4][4];
int Get(int state, int col)
{
	int a=state%4;
	state/=4;
	int b=state%4;
	state/=4;
	int c=state%4;
	state/=4;
	set<int> st;
	st.insert(0);
	st.insert(1);
	st.insert(2);
	st.insert(3);
	if(can[col][1]) st.erase(a);
	if(can[col][2]) st.erase(b);
	if(can[col][3]) st.erase(c);
	int d=*st.begin();
	int ans=(b*4+a)*4+d;
	return ans;
}
const int N=1050;
int n,m;
vector<pair<int,int>> pos[N];
int a[N];
void input()
{
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]);
	scanf("%i",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,col;
		scanf("%i %i %i",&x,&y,&col);
		pos[x].pb({y,col});
	}
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) scanf("%i",&can[i][j]);
}
bool was[M];
void BFS(int st)
{
	queue<int> q;
	q.push(st);
	was[st]=1;
	while(q.size())
	{
		int state=q.front();
		q.pop();
		for(int col=1;col<=3;col++)
		{
			int nxt=Get(state,col);
			if(!was[nxt])
			{
				q.push(nxt);
				was[nxt]=1;
			}
		}
	}
	for(int i=0;i<M;i++) if(was[i]) possible.pb(i);
}
void preprocess()
{
	BFS(63);
    for(int i=0;i<possible.size();i++)
	{
		for(int j=1;j<=3;j++)
		{
			match[0].a[i][GetIndex(Get(possible[i],j))]++;
			match[j].a[i][GetIndex(Get(possible[i],j))]++;
		}
	}
	po[0]=match[0];
	for(int i=1;i<L;i++) po[i]=po[i-1]*po[i-1];
}
Vector Solve(int idx)
{
	Vector start;
	start.init();
	start.v[possible.size()-1]=1;
	sort(pos[idx].begin(),pos[idx].end());
	pos[idx].pb({a[idx]+1,-1});
	int now=0;
	Matrix tmp;
	tmp.id();
	for(auto p:pos[idx])
	{
		int i=p.first;
		int col=p.second;
		int d=i-now-1;
		now=i;
		//tmp=tmp*pow(d);
		for(int j=0;j<L;j++) if(d>>j&1) start=start*po[j];
		if(col!=-1) start=start*match[col];
	}
	Vector ans=start;
	return ans;
}
int ways[N][4];
int dp[N][4];
void Solve()
{
	for(int i=1;i<=n;i++)
	{
		Vector vec=Solve(i);
		for(int j=0;j<possible.size();j++) ways[i][possible[j]%4]=add(ways[i][possible[j]%4],vec.v[j]);
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				dp[i][j^k]=add(dp[i][j^k],mul(dp[i-1][j],ways[i][k]));
			}
		}
	}
	printf("%i\n",dp[n][0]);
}
int main()
{
	input();
	preprocess();
	Solve();
	return 0;
}