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
char a[N],b[N];
int aa[N],ab[N],ba[N],bb[N];
int saa,sab,sba,sbb;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	scanf("%s",a+1);
	scanf("%s",b+1);
	int sa=0,sb=0;
	for(int i=1;i<=n;i++) if(a[i]=='a') sa++;
	for(int i=1;i<=n;i++) if(b[i]=='a') sb++;
	if((sa+sb)%2!=0)
	{
		cout<<"-1\n";
		return 0; 
	}
	vector<int> v1,v2;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='a'&&b[i]=='b') v1.pb(i);
		if(a[i]=='b'&&b[i]=='a') v2.pb(i);
	}
	sa=v1.size(),sb=v2.size();
	cout<<(sa/2+sb/2+sa%2+sb%2)<<endl;
	for(int i=1;i<sa;i+=2) printf("%d %d\n",v1[i-1],v1[i]);
	for(int i=1;i<sb;i+=2) printf("%d %d\n",v2[i-1],v2[i]);
	if(sa%2==1)
	{
		printf("%d %d\n",v1.back(),v1.back());
		printf("%d %d\n",v1.back(),v2.back());
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}