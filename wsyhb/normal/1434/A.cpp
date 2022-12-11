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
int a[6];
const int max_cnt=6e5+5;
struct node
{
	int val,id;
}b[max_cnt];
inline bool cmp(const node &x,const node &y)
{
	return x.val<y.val;
}
const int max_n=1e5+5;
int cnt[max_n];
int main()
{
	for(int i=0;i<6;++i)
		a[i]=read_int();
	int n=read_int();
	int cnt_now=0;
	for(int i=1;i<=n;++i)
	{
		int x=read_int();
		for(int j=0;j<6;++j)
		{
			++cnt_now;
			b[cnt_now].val=x-a[j];
			b[cnt_now].id=i;
//			printf("val=%d id=%d\n",b[cnt_now].val,b[cnt_now].id);
		}
	}
	sort(b+1,b+cnt_now+1,cmp);
//	printf("--------------------------\n");
//	for(int i=1;i<=cnt_now;++i)
//		printf("val=%d id=%d\n",b[i].val,b[i].id);
	int tot=n;
	int r=1;
	int ans=1e9;
	for(int i=1;i<=cnt_now;++i)
	{
		if(i>1)
		{
			--cnt[b[i-1].id];
			if(cnt[b[i-1].id]==0)
				++tot;
		}
		while(r<=cnt_now&&tot>0)
		{
			++cnt[b[r].id];
			if(cnt[b[r].id]==1)
				--tot;
			++r;
		}
//		printf("i=%d r=%d tot=%d\n",i,r,tot);
		if(tot>0)
			break;
		ans=min(ans,b[r-1].val-b[i].val);
	}
	printf("%d",ans);
	return 0;
}