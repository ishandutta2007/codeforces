#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
int aa[N];
int a,b,c,d;
void work1()
{
	for(int i=1;i<=a;i++) aa[2*i-1]=0;
	for(int i=a+1;i<=a+c;i++) aa[2*i-1]=2;
	for(int i=1;i<=b;i++) aa[2*i]=1;
	for(int i=b+1;i<=b+d;i++) aa[2*i]=3;
	for(int i=1;i<a+b+c+d;i++)
	{
		if(abs(aa[i+1]-aa[i])!=1)
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=a+b+c+d;i++) printf("%d ",aa[i]);
}
void work2()
{
	for(int i=1;i<=d;i++) aa[2*i-1]=3;
	for(int i=d+1;i<=b+d;i++) aa[2*i-1]=1;
	for(int i=1;i<=c;i++) aa[2*i]=2;
	for(int i=c+1;i<=c+a;i++) aa[2*i]=0;
	for(int i=1;i<a+b+c+d;i++)
	{
		if(abs(aa[i+1]-aa[i])!=1)
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=a+b+c+d;i++) printf("%d ",aa[i]);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>a>>b>>c>>d;
	if(abs(a+c-b-d)>1)
	{
		cout<<"NO\n"; return 0;
	}
	if(a+c>=b+d) work1();
	else work2();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

//