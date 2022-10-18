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
#define N 200005
char a[N];
int l,r;
int kl,kr;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	scanf("%s",a+1);
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]>='0'&&a[i]<='9') l+=a[i]-'0';
		else kl++;
	}
	for(int i=n/2+1;i<=n;i++)
	{
		if(a[i]>='0'&&a[i]<='9') r+=a[i]-'0';
		else kr++;
	}
	if(kl>kr)
	{
		swap(kl,kr);
		swap(l,r);
	}
	if(kl==kr&&kl==0)
	{
		if(l==r)
		{
			cout<<"Bicarp\n";
		}
		else cout<<"Monocarp\n";
		return 0;
	}
	if(kl==kr)
	{
		int d=abs(l-r);
		if(d!=0) cout<<"Monocarp\n";
		else cout<<"Bicarp\n";
		return 0;
	}
	else
	{
		int d=r-l;
		if(d>=0) cout<<"Monocarp\n",exit(0);
		d=l-r;
		if(d%9!=0) cout<<"Monocarp\n",exit(0);
		int r=d/9;
		if(r!=(kr-kl)/2) cout<<"Monocarp\n",exit(0);
		cout<<"Bicarp\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}