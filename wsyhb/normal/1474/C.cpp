#include<bits/stdc++.h>
using namespace std;
namespace IO
{
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
	        flag=(c=='-'?-1:1);
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
	char st[13];
	int _top;
	void Write(int x)
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
		while(x)
		{
			st[++_top]=x%10+'0';
			x/=10;
		}
		while(_top>0)
			putchar(st[_top--]);
	}
}
const int max_n=1e3+5;
int a[max_n<<1];
multiset<int> s;
multiset<int>::iterator it;
typedef pair<int,int> P;
vector<P> ans;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i)
			scanf("%d",a+i);
		sort(a+1,a+2*n+1);
		string res="NO";
		for(int i=1;i<2*n;++i)
		{
			s.clear();
			for(int j=1;j<2*n;++j)
			{
				if(j!=i)
					s.insert(a[j]);
			}
			ans.clear();
			ans.push_back(P(a[i],a[2*n]));
			int x=a[2*n];
			bool flag=true;
			for(int j=1;j<n;++j)
			{
				int p=*(--s.end());
				s.erase(--s.end());
				it=s.lower_bound(x-p);
				if(it!=s.end()&&*it==x-p)
				{
					ans.push_back(P(p,x-p));
					s.erase(it);
					x=p;
				}
				else
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				res="YES";
				break;
			}
		}
		if(res=="NO")
			puts("NO");
		else
		{
			puts("YES");
			printf("%d\n",ans[0].first+ans[0].second);
			for(int i=0;i<n;++i)
				printf("%d %d\n",ans[i].first,ans[i].second);
		}
	}
	return 0;
}