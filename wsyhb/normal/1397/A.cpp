#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
inline char read_char()
{
    if(S==T) T=(S=buf)+fread(buf,1,buffer_size,stdin);
    return S!=T?*(S++):EOF;
}
inline int read_int()
{
    bool flag=false;
    char c=read_char();
    while(c<'0'||c>'9')
    {
        flag=(c=='-'?true:flag);
        c=read_char();
    }
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c-'0');
        c=read_char();
    }
    return flag?-x:x;
}
const int max_l=1e3+5; 
char s[max_l];
int cnt[30];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<26;++i) cnt[i]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s);
			for(int j=0;j<strlen(s);++j)
				cnt[s[j]-'a']++;
		}
		bool flag=true;
		for(int i=0;i<26;++i)
			if(cnt[i]%n)
			{
				flag=false;
				break;
			}
		printf(flag?"YES\n":"NO\n");
	}
	return 0;
}