#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 100005
int st[N][19],a[N],lg[N],n;
int query(int l,int r)
{
	int t=lg[r-l+1];
	return __gcd(st[l][t],st[r-(1<<t)+1][t]);
}
inline int s(int n){return n*(n+1)/2;}
int f(int n,int a,int b,int c)
{
	if(!a) return (n+1)*(b/c);
	if(a<0||b<0||a>=c||b>=c)
	{
		int A=a%c,B=b%c;
		(A<0)&&(A+=c),(B<0)&&(B+=c);
		return f(n,A,B,c)+((a-A)/c)*s(n)+((b-B)/c)*(n+1);
	}
	int m=(a*n+b)/c;return n*m-f(m-1,c,c-b-1,a);
}
int chk(int val)
{
	int ans=0,r=1,sum=a[1],cnt=a[1],las=0;
	for(int i=1;i<=100000;i++)
	{
		if(!a[i]) continue;
		if(i>val) continue;
		sum-=i*a[i],cnt-=a[i];
		int tmp=0;
		if(val/i<=a[i])
		{
			ans+=(val/i)*(a[i]-val/i+1);
			tmp=a[i]-val/i+1;
		}
		while(r<=100000&&i*(a[i]-tmp)+sum<=val)
		{
			r++;
			cnt+=a[r],sum+=r*a[r];
		}
		// assert(tmp<=a[i]);
		if(r>100000)
		{
			ans+=(a[i]-tmp)*cnt+s(a[i]-tmp);
			continue;
		}
		// printf("%d %d\n",i,sum);
		while(tmp<a[i])
		{
			if(sum>=val)
			{
				int R=val-(sum-r*a[r])-i*(a[i]-tmp);
				ans+=(a[i]-tmp)*(cnt-a[r])+s(a[i]-tmp);
				// printf("%lld %lld %lld %lld\n",a[i]-tmp-1,i,R,r);
				ans+=f(a[i]-tmp-1,i,R,r);
				tmp=a[i];
			}
			else
			{
				int QAQ=(val-sum-1)/i;
				assert(tmp+QAQ<=a[i]);
				int R=val-(sum-r*a[r]+QAQ*i)-i*(a[i]-tmp-QAQ);
				ans+=(a[i]-tmp-QAQ)*(cnt-a[r]+QAQ)+s(a[i]-tmp-QAQ);
				ans+=f(a[i]-tmp-QAQ-1,i,R,r);
				tmp=a[i]-QAQ;
			}
			// cout<<ans<<endl;
			if(tmp==a[i]) break;
			while(r<=100000&&i*(a[i]-tmp)+sum<=val)
			{
				r++;
				cnt+=a[r],sum+=r*a[r];
			}
			if(r>100000)
			{
				ans+=(a[i]-tmp)*cnt+s(a[i]-tmp);
				break;
			}
		}
		// printf("%lld %lld\n",i,ans-las);
		las=ans;
	}
	return ans;
}
signed main()
{
	for(int i=2;i<N;i++) lg[i]=lg[i/2]+1;
	cin>>n;
	for(int i=1;i<=n;i++) st[i][0]=read();
	for(int i=1;i<=18;i++) for(int j=1;j+(1<<i)-1<=n;j++) st[j][i]=__gcd(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for(int i=1;i<=n;i++)
	{
		int cur=n;
		while(cur>=i)
		{
			int val=query(i,cur),l=i,r=cur,res;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(query(i,mid)>val) l=mid+1;
				else r=mid-1,res=mid;
			}
			a[val]+=cur-res+1;
			// printf("%d %d %d\n",i,cur,val);
			cur=res-1;
		}
	}
	// for(int i=1;i<=12;i++) printf("%d%c",a[i]," \n"[i==12]);
	int l=1,r=INF,ans;
	int sum=n*(n+1)/2; sum=sum*(sum+1)/2;
	// cout<<sum<<endl;
	// cout<<chk(30)<<endl;
	// for(int i=1;i<=100;i++) printf("%lld\n",chk(i));
	// return 0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chk(mid)>=(sum+1)/2) ans=mid,r=mid-1;
		else l=mid+1; 
	}
	cout<<ans<<endl;
	return 0;
}