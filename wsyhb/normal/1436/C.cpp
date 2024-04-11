#include<bits/stdc++.h>
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
        x=x*10+(c^48);
        c=read_char();
    }
    return flag?-x:x;
}
const int max_n=1e3+5;
int mark[max_n];
const int P=1e9+7;
int main()
{
	int n,x,pos;
	scanf("%d%d%d",&n,&x,&pos);
	int left=0,right=n;
	while(left<right)
	{
		int middle=(left+right)/2;
		if(pos+1>=middle+1)
		{
			mark[middle]=1;
			left=middle+1;
		}
		else
		{
			mark[middle]=2;
			right=middle;
		}
	}
	int cnt_1=0,cnt_2=0;
	for(int i=0;i<n;++i)
		if(mark[i]&&i!=pos)
		{
			if(mark[i]==1)
				++cnt_1;
			else
				++cnt_2;
		}
	int d1=x-1,d2=n-x;
	int ans=1;
	while(cnt_1)
	{
		ans=1ll*ans*d1%P;
		--d1;
		--cnt_1;
	}
	while(cnt_2)
	{
		ans=1ll*ans*d2%P;
		--d2;
		--cnt_2;
	}
	for(int i=1;i<=d1+d2;++i)
		ans=1ll*ans*i%P;
	printf("%d",ans);
	return 0;
}