#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) ((v).size())
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
in k,x,n,m;
in s[55];
in e[55];
in a[55];
void prl(in l){
  cout<<char('A'+l);
}
void pr(in st, in ed, in ct, in sz){
  if(sz==0)
    return;
  if(sz==1){
    prl(st);
    return;
  }
  if(sz==2){
    prl(st);
    prl(ed);
    return;
  }
  prl(st);
  if(ct==0){
    pr(1,ed,0,sz-1);
    return;
  }
  if(st==0){
    prl(2);
    ct--;
    if(ct==0)
      pr(ed,ed,ct,sz-2);
    else
      pr(0,ed,ct,sz-2);
    return;
  }
  pr(0,ed,ct,sz-1);
}
int main(){
  cin>>k>>x>>n>>m;
  forn(s1,3){
    forn(e1,3){
      forn(s2,3){
	forn(e2,3){
	  forn(a1,55){
	    forn(a2,55){
	      if(n==1 && s1!=e1)
		continue;
	      if(m==1 && s2!=e2)
		continue;
	      if(s1==0 && e1==2 && n==2 && a1!=1)
		continue;
	      if(s2==0 && e2==2 && m==2 && a2!=1)
		continue;
	      if(a1*2+(s1!=0)+(n!=1 && e1!=2)>n)
		continue;
	      if(a2*2+(s2!=0)+(m!=1 && e2!=2)>m)
		continue;
	      s[1]=s1;
	      s[2]=s2;
	      e[1]=e1;
	      e[2]=e2;
	      a[1]=a1;
	      a[2]=a2;
	      for(in i=3;i<=k;i++){
		a[i]=a[i-2]+a[i-1];
		s[i]=s[i-2];
		e[i]=e[i-1];
		if(e[i-2]==0 && s[i-1]==2)
		  a[i]++;
	      }
	      if(a[k]==x){
		//cout<<s1<<" "<<e1<<" "<<a1<<" "<<s2<<" "<<e2<<" "<<a2<<endl;
		//cout<<s[3]<<" "<<e[3]<<" "<<a[3]<<" "<<s[4]<<" "<<e[4]<<" "<<a[4]<<endl;
		pr(s1,e1,a1,n);
		cout<<endl;
		pr(s2,e2,a2,m);
		cout<<endl;
		return 0;
	      }
	    }
	  }
	}
      }
    }
  }
  cout<<"Happy new year!"<<endl;
  return 0;
}