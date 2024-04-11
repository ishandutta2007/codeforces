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
const int max_n=3e4+5;
int a[max_n],b[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		long long sum=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			sum+=a[i];
			b[i]=a[i]-a[i-1];
		}
		for(int i=2;i<=n;++i)
			if(b[i]<0)
			{
				b[1]+=b[i];
				sum+=1ll*(i-1)*b[i];
				b[i]=0;
			}
		if(sum<0||b[1]<0)
		{
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=n;++i)
			sum-=1ll*(n-i+1)*b[i];
		if(sum>=0&&sum%n==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}