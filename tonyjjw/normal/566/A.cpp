#include<stdio.h>
#include<algorithm>
#define ML 800000
#define MN 100000
#pragma warning(disable:4996)
using namespace std;

int N;
int p1[MN],p2[MN];
int ans[MN];
char s[ML+1];

struct NODE{
	int next[26];
	int p, d;
	NODE(int p_=-1){
		for(int k=0;k<26;k++)next[k]=-1;
		p=p_;
		d=0;
	}
}node[ML+1];

int ncnt=1;

int h1[MN],h2[MN],s1,s2;

bool cmp1(int a,int b){
	return p1[a]<p1[b];
}
bool cmp2(int a,int b){
	return p2[a]<p2[b];
}

void push1(int key){
	h1[s1++]=key;
	push_heap(h1,h1+s1,cmp1);
}
void push2(int key){
	h2[s2++]=key;
	push_heap(h2,h2+s2,cmp2);
}
void pop1(){
	pop_heap(h1,h1+s1,cmp1);
	h1[--s1]=0;
}
void pop2(){
	pop_heap(h2,h2+s2,cmp2);
	h2[--s2]=0;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s",s);
		int p=0;
		for(int j=0;s[j]!=0;j++){
			if(node[p].next[s[j]-'a']==-1){
				node[p].next[s[j]-'a']=ncnt;
				node[ncnt]=NODE(p);
				node[ncnt].d=node[p].d+1;
				ncnt++;
			}
			p=node[p].next[s[j]-'a'];
		}
		p1[i]=p;
	}
	for(int i=0;i<N;i++){
		scanf("%s",s);
		int p=0;
		for(int j=0;s[j]!=0;j++){
			if(node[p].next[s[j]-'a']==-1){
				node[p].next[s[j]-'a']=ncnt;
				node[ncnt]=NODE(p);
				node[ncnt].d=node[p].d+1;
				ncnt++;
			}
			p=node[p].next[s[j]-'a'];
		}
		p2[i]=p;
	}
	for(int i=0;i<N;i++)push1(i),push2(i);
	int ansv=0;
	while(s1+s2>0){
		int t1=h1[0],t2=h2[0];
		if(p1[t1]==p2[t2]){
			pop1();
			pop2();
			ans[t1]=t2;
			ansv+=node[p1[t1]].d;
		}
		else if(p1[t1]>p2[t2]){
			pop1();
			p1[t1]=node[p1[t1]].p;
			push1(t1);
		}
		else{
			pop2();
			p2[t2]=node[p2[t2]].p;
			push2(t2);
		}
	}
	printf("%d\n",ansv);
	for(int i=0;i<N;i++)printf("%d %d\n",i+1,ans[i]+1);
	return 0;
}