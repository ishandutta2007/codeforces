#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 300005
char a[N],s[N];
int pre[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	scanf("%s",a+1);
	int sum=0,minn=0,pos=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(a[i]=='('?1:-1);
		if(sum<minn) minn=sum,pos=i;
	}
	if(sum!=0)
	{
		printf("0\n1 1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=a[(pos+i-1)%n+1];
//		cout<<s[i]<<" ";
	}
	vector<int> v;
	v.pb(0);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+(s[i]=='('?1:-1);
		if(pre[i]==0) cnt++,v.pb(i);
	}
	int ans=cnt,L=1,R=1;
//	cout<<ans<<endl;
	for(int i=1;i<v.size();i++)
	{
		int l=v[i-1]+1,r=v[i];
		int tmp=0;
		for(int j=l;j<=r;j++)
		{
			if(pre[j]==1) tmp++;
		}
		if(tmp>ans) ans=tmp,L=l,R=r;
	}
//	cout<<ans<<endl;
	v.clear();
	for(int i=1;i<=n;i++) if(pre[i]==1) v.pb(i);
	for(int i=1;i<v.size();i++)
	{
		int l=v[i-1]+1,r=v[i];
		if(pre[l]==0) continue;
		int tmp=0;
		for(int j=l;j<=r;j++)
		{
			if(pre[j]==2) tmp++;
		}
		if(cnt+tmp>ans) ans=cnt+tmp,L=l,R=r;
	}
	printf("%d\n%d %d\n",ans,(L+pos-1)%n+1,(R+pos-1)%n+1);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}