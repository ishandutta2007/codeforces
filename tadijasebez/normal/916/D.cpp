#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100050;
const int M=32*N*2;
const int mx=1e9;
int id[M>>1],go[M>>1][26],cnt,root1[N];
string word;
void Insert(int p, int &c, int pos, int val)
{
	c=++cnt;id[c]=id[p];
	for(int i=0;i<26;i++) go[c][i]=go[p][i];
	if(pos>=word.size()){ id[c]=val;return;}
	Insert(go[p][word[pos]-'a'],go[c][word[pos]-'a'],pos+1,val);
}
void Insert(int p, int &c, string s, int val)
{
	word=s;
	Insert(p,c,0,val);
}
int Find(int c, int pos)
{
	if(pos>=word.size()) return id[c];
	return Find(go[c][word[pos]-'a'],pos+1);
}
int Find(int c, string s)
{
	word=s;
	return Find(c,0);
}
int sum[M],ls[M],rs[M],clock,root2[N];
void Set(int p, int &c, int ss, int se, int qi, int f)
{
	c=++clock;sum[c]=sum[p]+f;ls[c]=ls[p];rs[c]=rs[p];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,f);
	else Set(rs[p],rs[c],mid+1,se,qi,f);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return 0;
	if(!c) return 0;
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return sum[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	string s;
	int q,j=0,x;
	char t[50];
	scanf("%i",&q);
	while(q--)
	{
		j++;
		root1[j]=root1[j-1];
		root2[j]=root2[j-1];
		scanf("%s",&t);
		if(t[0]=='s')
		{
			cin >> s;
			scanf("%i",&x);
			int id=Find(root1[j],s);
			if(id) Set(root2[j],root2[j],1,mx,id,-1);
			Set(root2[j],root2[j],1,mx,x,1);
			Insert(root1[j],root1[j],s,x);
		}
		if(t[0]=='r')
		{
			cin >> s;
			int id=Find(root1[j],s);
			if(id) Set(root2[j],root2[j],1,mx,id,-1);
			Insert(root1[j],root1[j],s,0);
		}
		if(t[0]=='q')
		{
			cin >> s;
			int id=Find(root1[j],s);
			if(id) printf("%i\n",Get(root2[j],1,mx,1,id-1));
			else printf("-1\n");
			fflush(stdout);
		}
		if(t[0]=='u')
		{
			scanf("%i",&x);
			root1[j]=root1[j-x-1];
			root2[j]=root2[j-x-1];
		}
	}
	return 0;
}