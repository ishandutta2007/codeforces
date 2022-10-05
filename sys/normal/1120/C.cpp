// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
const int Maxn=5005;
int n,dp[Maxn],ct,a,b;
string str;
struct node
{
	node *link,*son[27];
	int len;
}*root,*q,*tmp,*last,pool[2*Maxn];
void create(node* &t)
{
	t=&pool[++ct];
}
void insert(int x)
{
	node* cur;
	tmp=last;
	create(cur);
	cur->len=tmp->len+1;
	for(;tmp!=NULL&&tmp->son[x]==NULL;tmp=tmp->link) tmp->son[x]=cur;
	if(tmp==NULL)
		cur->link=root;
	else
	{
		q=tmp->son[x];
		if(tmp->len+1==q->len)
			cur->link=q;
		else
		{
			node* clone;
			create(clone);
			*clone=*q;
			clone->len=tmp->len+1;
			for(;tmp!=NULL&&tmp->son[x]==q;tmp=tmp->link) tmp->son[x]=clone;
			cur->link=q->link=clone;
		}
	}
	last=cur;
}
int main()
{
	create(root);
	last=root; 
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d%d",&n,&a,&b);
	dp[0]=a;
	cin>>str;
	for(int i=0;i<n;i++)
	{
		dp[i+1]=min(dp[i+1],dp[i]+a);
		insert(str[i]-'a');
		node* now=root;
		for(int j=i+1;j<n;j++)
		{
			if(now->son[str[j]-'a'])
			{
				now=now->son[str[j]-'a'];
				dp[j]=min(dp[j],dp[i]+b);
			}
			else break;
		}
	}
	printf("%d",dp[n-1]);
	return 0;
}