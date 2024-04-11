#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 2005
bool val[N];
void query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	char opt;
	cin>>opt;
	if(opt=='Y') val[x]=0;
}
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) val[i]=1;
	k=max(1,k/2);
	int len=n/k;
	for(int i=1;i<len;i++)
	{
		for(int j=1;j<=min(i,len-i);j++)
		{
			cout<<"R"<<endl;
			fflush(stdout);
			for(int x=j;x<=len;x+=i)
			{
				for(int c=(x-1)*k+1;c<=x*k;c++) query(c);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=val[i];
	printf("! %d\n",ans); fflush(stdout);
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}

//