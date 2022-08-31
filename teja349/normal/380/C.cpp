#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;
#define vi vector <int>;

typedef struct{
	int a;
	int b;
	int c;
}mystr;
int construct(int node,int b,int e,mystr*m,int*v);
mystr query(int node,int b,int e,int i,int j,mystr*m);
int main(){
	
	char t;
	int n,i=0;
	int v[1000002];
	t=getchar();
	while(t=='('|| t==')'){
		if(t=='(')
			v[i]=1;
		else
			v[i]=-1;
		t=getchar();
		i++;
	}

	n=i;
	
	int k=n;
		int val=0;
		while(k){
			val++;
			k=k/2;
		}
	mystr m[4000009];
	construct(1,0,n-1,m,v);
	
	int q,l,r;
	cin>>q;
	while(q--){
		cin>>l>>r;
		mystr ans=query(1,0,n-1,l-1,r-1,m);
		cout<<ans.b<<endl;
	}

}
int construct(int node,int b,int e,mystr*m,int*v){
	if(b==e)
	{
		if(v[b]==1){
			m[node].a=1;
			m[node].b=0;
			m[node].c=0;
		}
		else{
			m[node].a=0;
			m[node].b=0;
			m[node].c=1;
		}
		return 0;

	}
	construct(2*node,b,(b+e)/2,m,v);
	construct(2*node+1,(b+e)/2+1,e,m,v);
	if(m[2*node].a<m[2*node+1].c){
		m[node].b = m[2*node].b+m[2*node+1].b+2*(m[2*node].a);
		m[node].c = m[2*node].c+m[2*node+1].c-m[2*node].a;
		m[node].a = m[2*node+1].a;
	}
	else{
		m[node].b =m[2*node].b+m[2*node+1].b+2*(m[2*node+1].c);
		m[node].a =m[2*node].a+m[2*node+1].a-m[2*node+1].c;
		m[node].c =m[2*node].c;

	}
	//cout<<node<<" "<<m[node].a<<endl;
	return 0;
}
mystr query(int node,int b,int e,int i,int j,mystr*m){
	if(b>j || e<i)
	{
	
		mystr my;
		my.a=-1;
		my.b=0;
		my.c=0;
		return my;
	}
	if(i<=b && e<=j){
		return m[node];
	}
	mystr p1,p2,p;
	p1=query(2*node,b,(b+e)/2,i,j,m);
	p2=query(2*node+1,(b+e)/2+1,e,i,j,m);
	if(p1.a==-1)
		return p2;
	if(p2.a==-1)
		return p1;
	if(p1.a<p2.c){
		p.b = p1.b + p2.b +  2*(p1.a);
		p.c = p1.c + p2.c - p1.a;
		p.a = p2.a;
	}
	else{
		p.b=p1.b +p2.b +2*(p2.c);
		p.a=p1.a+p2.a-p2.c;
		p.c=p1.c;


	}
	return p;

}