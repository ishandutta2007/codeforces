#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int T,n;
char a[maxn],b[maxn],s[maxn],s2[maxn];
int maxlen;
int Len[maxn],Len1[maxn],Len2[maxn];
struct PAM
{
    int ch[maxn][27],fail[maxn],len[maxn],cnt[maxn],num[maxn],s[maxn];
    int n,tot,last;
    int newnode(int x){len[tot]=x;return tot++;}
    void init()
    {
    	for(int i=0;i<=tot;++i)memset(ch[i],0,sizeof(ch[i]));
    	for(int i=0;i<=tot;++i)fail[i]=len[i]=cnt[i]=num[i]=s[i]=Len[i]=0;
    	tot=0;
        newnode(0);newnode(-1);
        fail[0]=1;fail[1]=1;
        n=last=0;s[n]=-1;
    }
    int getfail(int x){while(s[n]!=s[n-len[x]-1])x=fail[x];return x;}
    void add(int x,int pos)
    {
        s[++n]=x;
        int t=getfail(last);
        if(!ch[t][x])
        {
            int now=newnode(len[t]+2);
            fail[now]=ch[getfail(fail[t])][x];
            ch[t][x]=now;
            num[now]=num[fail[now]]+1;
        }
        last=ch[t][x];
        cnt[last]++;
        Len[pos]=len[last];
    }
    void build(char *s,int N)
    {
        for(int i=1;i<=N;++i)add(s[i]-'a'+1,i);
        for(int i=tot;i;--i)cnt[fail[i]]+=cnt[i];
    }
}pam;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",a+1);
		n=strlen(a+1);
		for(int i=1;i<=n;++i)b[i]=a[n-i+1];
		maxlen=0;
		for(int i=1;i<=n/2;++i)
		{
			if(a[i]==b[i])maxlen++;
			else break;
		}
		int N=0; 
		for(int i=maxlen+1;i<=n-maxlen;++i)s[++N]=a[i];
		for(int i=1;i<=N;++i)s2[i]=s[N-i+1];
		int mxp=0,mxs=0;
		pam.init();
		pam.build(s,N);
		for(int i=1;i<=N;++i)if(Len[i]==i)mxp=max(mxp,i);
		pam.init();
		pam.build(s2,N);
		for(int i=1;i<=N;++i)if(Len[i]==i)mxs=max(mxs,i);
		if(mxp>=mxs)
		{
			for(int i=1;i<=maxlen;++i)printf("%c",a[i]);
			for(int i=1;i<=mxp;++i)printf("%c",s[i]);
			for(int i=maxlen;i>=1;--i)printf("%c",a[i]);
		}
		else
		{
			for(int i=1;i<=maxlen;++i)printf("%c",a[i]);
			for(int i=1;i<=mxs;++i)printf("%c",s2[i]);
			for(int i=maxlen;i>=1;--i)printf("%c",a[i]);
		}
		puts("");
	}
}