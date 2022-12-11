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
vector<int> prime;
vector<int> cnt;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long p;
		int q;
		scanf("%lld%d",&p,&q);
		if(p%q!=0)
		{
			printf("%lld\n",p);
			continue;
		}
		prime.clear();
		cnt.clear();
		for(int i=2;1ll*i*i<=q;++i)
			if(q%i==0)
			{
				prime.push_back(i);
				int c=0;
				while(q%i==0)
					q/=i,++c;
				cnt.push_back(c);
			}
		if(q!=1)
		{
			prime.push_back(q);
			cnt.push_back(1);
		}
		long long ans=p;
		for(int i=0;i<prime.size();++i)
		{
			int P=prime[i];
			int tot=0;
			long long t=p;
			while(t%P==0)
				t/=P,++tot;
			long long res=1;
			for(int j=1;j<=tot-cnt[i]+1;++j)
				res*=P;
			ans=min(ans,res);
		}
		printf("%lld\n",p/ans);
	}
	return 0;
}