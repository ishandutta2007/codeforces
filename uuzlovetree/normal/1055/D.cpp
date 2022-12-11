#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int n;
char a[maxn][maxn],b[maxn][maxn],S[maxn],T[maxn];
int same[maxn],L[maxn],R[maxn],Len[maxn];
struct KMP
{
	int nxt[maxn],len;
	char t[maxn];
	void clear(){len=nxt[0]=nxt[1]=0;}
	void init(char *s)
	{
		clear();
		len=strlen(s+1);
		for(int i=0;i<=len+1;++i)t[i]=s[i];
		for(int i=2;i<=len;++i)
		{
			nxt[i]=nxt[i-1];
			while(nxt[i]&&s[i]!=s[nxt[i]+1])nxt[i]=nxt[nxt[i]];
			nxt[i]+=(s[i]==s[nxt[i]+1]);
		}
	}
	int match(char *ss)
	{
		int len_s = strlen(ss+1);
		for(int i=1,j=1;i<=len_s;)
		{
			while (j!=1&&ss[i]!=t[j])j=nxt[j-1]+1;
			if(ss[i]==t[j])j++,i++;
			else i++;
			if (j==len+1)
			{
				return i-j+1;
			}
		}
		return 0;
	}
}kmp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i)scanf("%s",b[i]+1);
	int minlen=0;
	for(int i=1;i<=n;++i)
	{
		same[i]=1;
		int len=strlen(a[i]+1);
		Len[i]=len;
		for(int j=1;j<=len;++j)if(a[i][j]!=b[i][j])same[i]=0;
		if(!same[i])
		{
			for(int j=1;j<=len;++j)if(a[i][j]!=b[i][j])R[i]=j;
			for(int j=len;j>=1;--j)if(a[i][j]!=b[i][j])L[i]=j;
			minlen=R[i]-L[i]+1;
		}
	}
	bool yes=1;
	for(int i=1;i<=n;++i)if(!same[i]&&R[i]-L[i]+1!=minlen)yes=0;
	if(yes)
	{
		while(1)
		{
			int fl=1;
			char c=0;
			for(int i=1;i<=n;++i)if(!same[i])
			{
				if(!c)c=a[i][L[i]-1];
				if(L[i]==1||c!=a[i][L[i]-1])fl=0;
			}
			if(!fl)break;
			for(int i=1;i<=n;++i)if(!same[i])L[i]--;
		}
		while(1)
		{
			int fl=1;
			char c=0;
			for(int i=1;i<=n;++i)if(!same[i])
			{
				if(!c)c=a[i][R[i]+1];
				if(R[i]==Len[i]||c!=a[i][R[i]+1])fl=0;
			}
			
			if(!fl)break;
			for(int i=1;i<=n;++i)if(!same[i])R[i]++;
		}
		for(int i=1;i<=n;++i)if(!same[i])
		{
			for(int j=L[i];j<=R[i];++j)
			{
				S[j-L[i]+1]=a[i][j];
				T[j-L[i]+1]=b[i][j];
			}
		}
		for(int i=1;i<=n;++i)
		{
			int len=Len[i];
			kmp.clear();
			kmp.init(S);
			int pos=kmp.match(a[i]);
			if(pos!=L[i])yes=0;
			if(pos)
			{
				for(int j=L[i];j<=R[i];++j)if(T[j-L[i]+1]!=b[i][j])yes=0;
			}
		}
	}
	if(!yes)
	{
		puts("NO");
	}
	else
	{
		puts("YES");
		printf("%s\n",S+1);
		printf("%s\n",T+1);
	}
}