#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<utility>

#define mp make_pair

using namespace std;

map<int,string>m;
int s;

int main(){
   m.insert(mp(0,"zero"));
  m.insert(mp(1,"one"));
   m.insert(mp(2,"two"));
    m.insert(mp(3,"three"));
     m.insert(mp(4,"four"));
      m.insert(mp(5,"five"));
       m.insert(mp(6,"six"));
 m.insert(mp(7,"seven"));
  m.insert(mp(8,"eight"));
   m.insert(mp(9,"nine"));
    m.insert(mp(10,"ten"));
    
     m.insert(mp(11,"eleven"));
      m.insert(mp(12,"twelve"));
       m.insert(mp(13,"thirteen"));
        m.insert(mp(14,"fourteen"));
	 m.insert(mp(15,"fifteen"));
	  m.insert(mp(16,"sixteen"));
	   m.insert(mp(17,"seventeen"));
	   m.insert(mp(18,"eighteen"));
	    m.insert(mp(19,"nineteen"));
	     m.insert(mp(20,"twenty"));
	 m.insert(mp(30,"thirty"));
	  m.insert(mp(40,"forty"));
	   m.insert(mp(50,"fifty"));
	    m.insert(mp(60,"sixty"));
	     m.insert(mp(70,"seventy"));
	      m.insert(mp(80,"eighty"));
	       m.insert(mp(90,"ninety"));
	   scanf("%d",&s);
	   if(m.count(s)){cout<<m[s]<<endl;}
	   else{cout<<m[(s/10)*10]<<"-"<<m[s%10]<<endl;}
return 0;
}