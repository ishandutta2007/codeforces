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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 1000005
char ss[N],tt[N],s[N];
int ch[N][26],fa[N],len[N],dif[N],tp[N],cnt,las,n;
int pos[N],p[N],f[N],fr[N];
signed main()
{
	scanf("%s%s",ss+1,tt+1);
	n=strlen(ss+1);
	for(int i=1;i<=n;i++) s[i*2-1]=ss[i],s[i*2]=tt[i];
	// printf("%s\n",s+1);
	n*=2;
	cnt=las=2,len[1]=-1,fa[1]=fa[2]=1;
	for(int i=1;i<=n;i++)
	{
		while(s[i]!=s[i-len[las]-1]) las=fa[las];
		if(!ch[las][s[i]-'a'])
		{
			int tmp=fa[las]; cnt++;
			while(tmp&&s[i]!=s[i-len[tmp]-1]) tmp=fa[tmp];
			fa[cnt]=ch[tmp][s[i]-'a']?ch[tmp][s[i]-'a']:2;
			ch[las][s[i]-'a']=cnt,len[cnt]=len[las]+2;
			dif[cnt]=len[cnt]-len[fa[cnt]];
			tp[cnt]=dif[cnt]==dif[fa[cnt]]?tp[fa[cnt]]:fa[cnt];
		}
		las=ch[las][s[i]-'a'],pos[i]=las;
	}
	// for(int i=1;i<=n;i++) printf("%d : %d %d\n",i,pos[i],len[pos[i]]);
	memset(f,0x3f,sizeof(f)); f[0]=0;
	p[1]=p[2]=1;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0&&s[i-1]==s[i]&&f[i-2]<f[i]) f[i]=f[i-2],fr[i]=i-2;
		for(int j=pos[i];j>2;j=tp[j])
		{
			p[j]=i-len[tp[j]]-dif[j];
			// printf("%d %d %d\n",i,j,p[j]);
			// printf("** %d %d\n",fa[j],p[fa[j]]);
			if(dif[j]==dif[fa[j]]&&f[p[fa[j]]]<f[p[j]]) p[j]=p[fa[j]];
			if(i%2==0&&f[p[j]]+1<f[i]) f[i]=f[p[j]]+1,fr[i]=p[j];
		}
	}
	// for(int i=1;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
	// for(int i=1;i<=n;i++) printf("%d%c",fr[i]," \n"[i==n]);
	if(f[n]>=inf) cout<<"-1\n";
	else
	{
		cout<<f[n]<<endl;
		int cur=n;
		while(cur)
		{
			int las=fr[cur];
			if(cur-las>2) printf("%d %d\n",las/2+1,cur/2);
			cur=las;
		}
	}
	return 0;
}