#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
bool flag_EOF;
inline char read_char()
{
    if(S==T)
        T=(S=buf)+fread(buf,1,buffer_size,stdin);
    return S!=T?*(S++):EOF;
}
inline int read_int()
{
    int flag=1;
    char c=read_char();
    while(c<'0'||c>'9')
    {
        if(c==EOF)
        {
            flag_EOF=true;
            return 0;
        }
        flag=(c=='-'?-1:flag);
        c=read_char();
    }
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=x*10+(c^48);
        c=read_char();
    }
    return x*flag;
}
inline void Write(int x)
{
    if(!x)
    {
        putchar('0');
        return;
    }
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    static char st[13];
    int head=0;
    while(x)
    {
        st[++head]=x%10+'0';
        x/=10;
    }
    while(head>0)
        putchar(st[head--]);
}
const int max_n=1e6+5;
char a[max_n],b[max_n];
const int cnt_letters=26+5;
int cnt_a[cnt_letters],cnt_b[cnt_letters];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d%s%s",&n,&k,a+1,b+1);
		for(int i=0;i<=25;++i)
			cnt_a[i]=cnt_b[i]=0;
		for(int i=1;i<=n;++i)
		{
			++cnt_a[a[i]-'a'];
			++cnt_b[b[i]-'a'];
		}
		int delta=0;
		bool flag_ans=true;
		for(int i=25;i>=0;--i)
		{
			if((cnt_a[i]-cnt_b[i])%k!=0)
			{
				flag_ans=false;
				break;
			}
			if(cnt_a[i]<cnt_b[i])
				delta+=cnt_b[i]-cnt_a[i];
			else
			{
				delta-=cnt_a[i]-cnt_b[i];
				if(delta<0)
				{
					flag_ans=false;
					break;
				}
			}
		}
		if(delta!=0)
			flag_ans=false;
		if(flag_ans)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}