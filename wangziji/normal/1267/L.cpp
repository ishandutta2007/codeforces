#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=1000005,MAXM=1005;

int n,m,k,cnt[26],p[MAXM];
char str[MAXN],ans[MAXM][MAXM];
bool cmp(int x,int y)
{
	for(int i=1;i<=m;++i)
		if(ans[x][i]!=ans[y][i])return ans[x][i]<ans[y][i];
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m),readint(k);
	scanf("%s",str);
	sort(str,str+n*m);
	for(int i=0;i<k*m;++i)++cnt[str[i]-'a'];
	int las=1;
	for(int i=1;i<=m;++i)
	{
		int sum=0;
		for(int j=0;j<26;++j)
		{
			sum+=cnt[j];
			if(sum>=k-las+1)
			{
				int cur=las;
				for(int t=j-1;t>=0;--t)
					while(cur<k && cnt[t])ans[cur++][i]=t+'a',--cnt[t];
				while(cur<k && cnt[j])ans[cur++][i]=j+'a',--cnt[j];
				ans[k][i]=j+'a',--cnt[j];
				cur=las-1;
				for(int t=25;t>=0;--t)
					while(cur && cnt[t])ans[cur--][i]=t+'a',--cnt[t];
				break;
			}
		}
		while(las<k && ans[las][i]!=ans[k][i])++las;
	}
	for(int i=1;i<=k;++i)p[i]=i;
	sort(p+1,p+k,cmp);
	for(int i=1;i<=k;++i)
		printf("%s\n",ans[p[i]]+1);
	for(int i=k+1;i<=n;++i)
	{
		for(int j=(i-1)*m;j<i*m;++j)
			putchar(str[j]);
		putchar('\n');
	}
	return 0;
}