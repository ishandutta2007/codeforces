#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char s[N],t[N];
struct node
{
	int pos,len;
}f[N],tmp;
int main()
{
	int n,m,k;
	scanf("%d%s%d%s%d",&n,s,&m,t,&k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(i<f[j].pos)
				continue;
			tmp=(node){i,f[j].len};
			while(s[tmp.pos]==t[tmp.len]&&tmp.len<m) 
			{
				tmp.pos++;
				tmp.len++;
			}
			if(tmp.len==m) 
			{
				puts("YES");
				return 0;
			}
			if(tmp.len>f[j+1].len) 
				f[j+1]=tmp;	
		}
	}
	puts("NO");
	return 0;
}