#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct node{
	int cnt;//the num of leaf of the node
	int sub;//the num of leaf in the subtree
	bool leaf;
	char ch;
	node* nxt[26];
	//int dp[2020];
	//int tmp[2020];
	vector<int> dp,tmp;
	bool visited;
	node()
	{
		leaf=false;
		ch='\0';
		cnt=0;
		sub=0;
		for(int i=0;i<26;i++)
		{
			nxt[i]=NULL;
		}
		visited=false;
	}
};

struct trie{
	node* root;
	trie()
	{
		root=new node();
	}
	void insert(string str)
	{
		node *p=root;
		int ln=str.size();
		for(int i=0;i<ln;i++)
		{
			int id=str[i]-'a';
			if((*p).nxt[id]==NULL)
			{
				p->nxt[id]=new node();
			}
			p->sub++;
			p=p->nxt[id];
			p->ch=str[i];
		}
		p->leaf=true;
		p->cnt++;
		p->sub++;
	}
	void rec(node* p)
	{
		if(p->visited) return;
		for(int i=0;i<26;i++) if(p->nxt[i]!=NULL) rec(p->nxt[i]);
		for(int i=0;i<=p->sub;i++) p->dp.push_back(0);
		for(int i=0;i<=p->sub;i++) p->tmp.push_back(0);
		int all=0;
		for(int i=0;i<=(p->sub);i++) p->tmp[i]=0;
		//if(p==root->nxt[0]) printf("%d %d\n",p->sub,p->cnt);
		for(int i=0;i<26;i++)
		{
			if(p->nxt[i]==NULL) continue;
			int now=(p->nxt[i])->sub;
			for(int a=0;a<=all+now;a++) p->tmp[a]=0;
			for(int n=0;n<=now;n++)
			{
				for(int a=0;a<=all;a++)
				{
					p->tmp[n+a]=max(p->tmp[n+a],p->dp[a]+(p->nxt[i])->dp[n]+n*(n-1)/2);
					//if(p==root->nxt[0]) printf("%d %d %d %d\n",n,a,(p->nxt[i])->dp[n],p->dp[a]);
				}
			}
			all+=now;
			for(int a=0;a<=all;a++) p->dp[a]=p->tmp[a];
		}
		for(int i=0;i<=all;i++) p->dp[i]=p->tmp[i];
		for(int i=0;i<=p->cnt;i++)
		{
			p->dp[all+i]=p->dp[all];
		}
		p->visited=true;
	}
};

string strs[2020];
int ln[2020];
int same[2020];

trie tr;

int main()
{
	int N,K;
	cin>>N>>K;
	for(int i=0;i<N;i++) cin>>strs[i];
	sort(strs,strs+N);
	for(int i=0;i<N;i++) ln[i]=strs[i].size();
	same[0]=ln[0],same[N-1]=ln[N-1];
	int dis=0;
	for(int i=1;i<N-1;i++)
	{
		bool flg=false;
		for(int j=0;j<ln[i];j++)
		{
			char pre=ln[i-1]<j+1?' ':strs[i-1][j];
			char nxt=ln[i+1]<j+1?' ':strs[i+1][j];
			if(strs[i][j]!=pre&&strs[i][j]!=nxt)
			{
				same[i]=j;
				flg=true;
				break;
			}
		}
		if(flg==false) same[i]=ln[i];
		if(same[i]==0) dis++;
	}
	for(int i=0;i<N;i++) strs[i]=strs[i].substr(0,same[i]);
	for(int i=0;i<N;i++) tr.insert(strs[i]);
	tr.rec(tr.root);
	if(N-dis<K) K=N-dis;
	cout<<(tr.root)->dp[K]<<"\n";
	return 0;
}