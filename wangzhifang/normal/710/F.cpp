#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_n 400000
using namespace std;
queue<int>q;
struct acam{
	int ch[max_n+3][26],fail[max_n+3],val[max_n+3],ed[max_n+3],root[19],tot,cnt,rt;
	acam():tot(0),cnt(20),rt(20){}
	void merge(int rt1,int rt2){
		ed[rt2]|=ed[rt1];
		for(int i=-1; ++i<26; )
			if(ch[rt1][i])
				if(!ch[rt2][i])
					ch[rt2][i]=ch[rt1][i];
				else
					merge(ch[rt1][i],ch[rt2][i]);
	}
	void build_fail(int r){
		while(!q.empty())
			q.pop();
		q.push(r);
		fail[r]=val[r]=0;
		int u,p,v;
		while(!q.empty()){
			u=q.front();
			q.pop();
			for(int i=-1; ++i<26; )
				if(ch[u][i]){
					for(q.push(v=ch[u][i]),p=fail[u]; p&&!ch[p][i]; p=fail[p]);
					fail[v]=(p?ch[p][i]:r);
					val[v]=val[fail[v]]+ed[v];
				}
		}
	}
	void ins(char *s){
		int len=strlen(s),tmp=rt;
		for(int i=-1; ++i<len; tmp=cnt)
			ch[tmp][s[i]-'a']=++cnt;
		ed[tmp]=1;
		for(int i=-1; ++i<19; )
			if (!root[i]){
				memcpy(ch[root[i]=i+1],ch[rt],sizeof(ch[rt]));
				memset(ch[rt],0,sizeof(ch[rt]));
				build_fail(root[i]);
				break;
			}
			else{
				merge(root[i],rt);
				root[i]=0;
			}
	}
	int r[max_n+3];
	int query(char *s){
		int len=strlen(s),tmp,ans=0;
		for(int j=-1; ++j<len; r[j]=s[j]-'a');
		for(int i=-1; ++i<19; )
			if(root[i]){
				tmp=root[i];
				for(int j=-1; ++j<len; )
					if(ch[tmp][r[j]])
						ans+=val[tmp=ch[tmp][r[j]]];
					else{
						for(; tmp&&!ch[tmp][r[j]]; tmp=fail[tmp]);
						ch[tmp][r[j]]?(ans+=val[tmp=ch[tmp][r[j]]]):(tmp=root[i]);
					}
			}
		return ans;
	}
}add,del;
char s[300003];
int main(){
	int op,t;
	scanf("%d",&t);
	for(++t; --t; fflush(stdout)){
		scanf("%d%s",&op,s);
		switch(op){
			case 1:
				add.ins(s);
				break;
			case 2:
				del.ins(s);
				break;
			case 3:
				printf("%d\n",add.query(s)-del.query(s));
				break;
		}
	}
	return 0;
}