#include<cstdio>
#include<cstring>
#include<algorithm>
#define P 1000000007
#define N 1000005

inline int fmo(int x){
	return x+((x>>31)&P);
}

int n;
char str[N],s[N];

struct node{
	int len,dif,f;
	node *fa,*top,*ch[26];
}t[N],*rt=t,*lst=t;
int tot;
inline node *nw(int len){
	node *p=t+(++tot);
	p->len=len;
	p->fa=p->top=rt;
	for(int i=0;i<26;i++)
		p->ch[i]=rt;
	return p;
}
inline node *gfa(node *p,int pos){
	while(s[pos]!=s[pos-p->len-1])
		p=p->fa;
	return p;
}
inline void init(){
	rt->top=rt;
	rt->fa=t+1;
	for(int i=0;i<26;i++)
		rt->ch[i]=rt;
	nw(-1);
}
inline void ins(int c,int pos){
	node *p=gfa(lst,pos);
	if(p->ch[c]==rt){
		node *q=nw(p->len+2);
		q->fa=gfa(p->fa,pos)->ch[c];
		p->ch[c]=q;
		q->dif=q->len-q->fa->len;
		q->top=q->dif==q->fa->dif?q->fa->top:q->fa;
	}
	lst=p->ch[c];
}

int f[N];

int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1,l=1,r=n;i<=n;i++)
		s[i]=str[(i&1)?l++:r--];
	init();
	f[0]=1;
	for(int i=1;i<=n;i++){
		ins(s[i]-'a',i);
		for(node *p=lst;p!=rt;p=p->top){
			p->f=f[i-p->top->len-p->dif];
			if(p->top!=p->fa)
				p->f=fmo(p->f+p->fa->f-P);
			if(i%2==0)
				f[i]=fmo(f[i]+p->f-P);
		}
	}
	printf("%d\n",f[n]);
}