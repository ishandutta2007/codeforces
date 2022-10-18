#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define ll long long
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
signed main()
{
	int T=read();
	while(T--)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		int x,y,x1,y1,x2,y2;
		scanf("%d %d %d %d %d %d\n",&x,&y,&x1,&y1,&x2,&y2);
		if(x1==x2&&(a||b))
		{
			printf("No\n"); continue;
		}
		if(y1==y2&&(c||d))
		{
			printf("No\n"); continue;
		}
		bool ok=1;
		ok&=(x+b-a>=x1&&x+b-a<=x2);
		ok&=(y+d-c>=y1&&y+d-c<=y2);
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
}