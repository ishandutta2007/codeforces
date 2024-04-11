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
int n,q;
const int max_n=100+5;
char s[max_n];
vector<int> now;
bool flag_ans;
void dfs(int x,int k,int tot)
{
	if(k==now.size())
	{
		if(tot>0)
			flag_ans=true;
		return;
	}
	if(x>n||k+(n-x+1)<now.size())
		return;
	if(s[x]==now[k])
	{
		dfs(x+1,k+1,tot);
		if(flag_ans)
			return;
		if(tot==0)
			dfs(x+1,k,tot+1);
	}
	else
		dfs(x+1,k,tot+(k>0?1:0));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&n,&q,s+1);
		while(q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			now.clear();
			for(int i=l;i<=r;++i)
				now.push_back(s[i]);
			flag_ans=false;
			dfs(1,0,0);
			if(flag_ans)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}