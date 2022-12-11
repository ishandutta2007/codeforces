#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
bool flag_EOF;
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
        if(c==EOF)
        {
            flag_EOF=true;
            return 0;
        }
        flag=(c=='-'?true:flag);
        c=read_char();
    }
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=x*10+(c^48);
        c=read_char();
    }
    return flag?-x:x;
}
const int max_n=1e5+5;
char op[max_n<<1][3];
int x[max_n<<1];
int ans[max_n];
stack<int> st;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0,now=0;
	for(int i=1;i<=(n<<1);++i)
	{
		scanf("%s",op[i]);
		if(op[i][0]=='+')
		{
			++cnt;
			st.push(++now);
		}
		else
		{
			--cnt;
			if(cnt<0)
			{
				printf("NO");
				return 0;
			}
			scanf("%d",x+i);
			ans[st.top()]=x[i];
			st.pop();
		}
	}
	now=0;
	for(int i=1;i<=(n<<1);++i)
	{
		if(op[i][0]=='+')
			q.push(ans[++now]);
		else
		{
			int val=q.top();
			q.pop();
			if(val!=x[i])
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;++i)
		printf("%d%c",ans[i],i<n?' ':'\n');
	return 0;
}