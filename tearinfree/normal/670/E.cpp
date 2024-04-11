#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> ip;

struct node{
	node *pa,*ch_st,*ch_en,*pr,*nx;
	node() {
		pa=ch_st=ch_en=pr=nx=NULL;
	}
};

int n,m,k;
char str[500011];
node *root=new node();

node *s;
int sf=0;

void make() {
	node *cur=root;
	for(int i=1;i<=n;i++) {
		if(str[i]=='(') {
			if(cur->ch_en==NULL) {
				cur->ch_en=new node();
				cur->ch_en->pa=cur;
				cur->ch_st=cur->ch_en;
			}
			else {
				node *nxt=new node();
				nxt->pa=cur;
				nxt->pr=cur->ch_en;
				cur->ch_en->nx=nxt;
				cur->ch_en=nxt;
			}
			cur=cur->ch_en;
			if(i==k) s=cur;
		}
		else {
			if(i==k) {
				s=cur;
				sf=1;
			}
			cur=cur->pa;
		}
	}
}
void travel(node *cur) {
	if(cur!=root) printf("(");
	
	if(cur->ch_st!=NULL) travel(cur->ch_st);
	if(cur!=root) printf(")");
	
	if(cur->nx!=NULL) travel(cur->nx);
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",str+1);
	make();
	scanf("%s",str);
	
	for(int i=0;i<m;i++) {
		if(str[i]=='L') {
			if(sf==1) {
				if(s->ch_en!=NULL) s=s->ch_en;
				else sf=0;
			}
			else {
				if(s->pr!=NULL) s=s->pr,sf=1;
				else s=s->pa;
			}
		}
		else if(str[i]=='R') {
			if(sf==0) {
				if(s->ch_st!=NULL) s=s->ch_st;
				else sf=1;
			}
			else {
				if(s->nx!=NULL) s=s->nx,sf=0;
				else s=s->pa;
			}
		}
		else {
			node *p=s->pr,*x=s->nx;
			if(p!=NULL) p->nx=x;
			else s->pa->ch_st=x;

			if(x!=NULL) x->pr=p;
			else s->pa->ch_en=p;
			
			if(x!=NULL) {
				s=x;
				sf=0;
			}
			else if(s->pa!=root) {
				s=s->pa;
				sf=1;
			}
			else if(p!=NULL){
				s=p;
				sf=1;
			}
			else {
				s=s->pa;
				sf=0;
			}
		}
	}
	travel(root);
	return 0;
}