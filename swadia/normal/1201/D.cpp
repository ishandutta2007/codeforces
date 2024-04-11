#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG LL i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG LL i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n,m,k,q;

struct tre
{
	LL r,c;
} tr[MAXN];

LL safe[MAXN];

bool cmp(tre t1,tre t2)
{
	return t1.r<t2.r || t1.r==t2.r && t1.c<t2.c;
}

LL x[MAXN];
LL pl=-1;
LL pr=-1;
LL dp[MAXN][4];
LL pos[MAXN][10];
int main()
{
	cin>>n>>m>>k>>q;
	bool f=true;
	RPT(i,0,k)
	{
		cin>>tr[i].r>>tr[i].c;
		if (tr[i].r==1)
			f=false;
	}
	if (f)
	{
		tr[k].r=1;
		tr[k].c=1;
		k++;
	}
	sort(tr,tr+k,cmp);
	RPT(i,0,k)
		x[i]=tr[i].c;
	RPT(i,0,q)
		cin>>safe[i];
	sort(safe,safe+q);
	RPT(i,0,4)
		pos[0][i]=1;
	LL * ptr;
	LL tmp;
	RPT(i,1,m+INF)
	{
		//cout<<pl<<' '<<pr<<endl; 
		pl=++pr;
		pr=pl;
		if (pl==k)
		{
			LL mi=INF;
			RPT(j,0,4)
				mi=min(mi,dp[i-1][j]);
			cout<<mi+tr[k-1].r-1;
			break;
		}
		while (tr[pr+1].r==tr[pl].r && pr<k-1)
			pr++;
		ptr=upper_bound(safe,safe+q,pos[i-1][0]);
		//WRT(pos[i-1][0]);
		//WRT(ptr-safe);
		//WRT(*(ptr-1));
		if (ptr==safe)
			dp[i][0]=INF;
		else
		{
			dp[i][0]=dp[i-1][0]+abs(*(ptr-1)-pos[i-1][0]);
			pos[i][0]=*(ptr-1);
		}
		
		ptr=lower_bound(safe,safe+q,pos[i-1][1]);
		if (ptr==safe+q)
			dp[i][1]=INF;
		else
		{
			dp[i][1]=dp[i-1][1]+abs(*(ptr)-pos[i-1][1]);
			pos[i][1]=*(ptr);
		}
		
		
		
		ptr=upper_bound(safe,safe+q,pos[i-1][2]);
		if (ptr==safe)
			dp[i][2]=INF;
		else
		{
			dp[i][2]=dp[i-1][2]+abs(*(ptr-1)-pos[i-1][2]);
			pos[i][2]=*(ptr-1);
		}
		ptr=lower_bound(safe,safe+q,pos[i-1][3]);
		if (ptr==safe+q)
			dp[i][3]=INF;
		else
		{
			//cout<<*(ptr)<<' '<<pos[i-1][3]<<endl;
			dp[i][3]=dp[i-1][3]+abs(*(ptr)-pos[i-1][3]);
			pos[i][3]=*(ptr);
			//cout<<*(ptr)<<endl;
		}
		if (i==1)
		{
			RPT(j,0,4)
			{
				dp[i][j]=0;
				pos[i][j]=1;
			}
		}
		//cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<' '<<dp[i][3]<<endl;
		//cout<<pos[i][0]<<' '<<pos[i][1]<<' '<<pos[i][2]<<' '<<pos[i][3]<<endl;
		
		LL tem[4];
		RPT(j,0,4)
			tem[j]=LLINF;
		RPT(j,0,4)
		{
			//WRT(pos[i][1]);
			//cout<<tr[pr].c<<' '<<pos[i][j]<<endl;
			//WRT(dp[i][j]+tr[pr].c-tr[pl].c+abs(tr[pr].c-pos[i][j]));
			tem[0]=tem[1]=min(tem[0],dp[i][j]+tr[pr].c-tr[pl].c+abs(tr[pr].c-pos[i][j]));
			tem[2]=tem[3]=min(tem[2],dp[i][j]+tr[pr].c-tr[pl].c+abs(pos[i][j]-tr[pl].c));
		}
		pos[i][0]=pos[i][1]=tr[pl].c;
		pos[i][2]=pos[i][3]=tr[pr].c;
		RPT(j,0,4)
			dp[i][j]=tem[j];
		//cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<' '<<dp[i][3]<<endl;
		//MRK();
		//cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<' '<<dp[i][3]<<endl;
		//cout<<pos[i][0]<<' '<<pos[i][1]<<' '<<pos[i][2]<<' '<<pos[i][3]<<endl;
	}
	
	return ~~(0^_^0);
}