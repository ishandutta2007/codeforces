#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int n,ansn,ansp,tn,tp,l1,l2,a,b;
string s1,s2;
int spr(char a,char b)
{
    if (a=='R')
    {
       if (b=='S') return 1;
       if (b=='P') return 2;
       return 0;
    } 
    if (a=='S')
    {
       if (b=='P') return 1;
       if (b=='R') return 2;
       return 0;
    } 
    if (a=='P')
    {
       if (b=='R') return 1;
       if (b=='S') return 2;
       return 0;
    } 
}
int main()
{
      cin>>n;
      cin>>s1;
      cin>>s2;
      l1=s1.size();l2=s2.size();
      a=l1;b=l2;
      if (a<b) swap(a,b);
      int c=a%b;
      while (c!=0) {a=b; b=c; c=a%b;}         
      int nn=l1*l2/b;
      int pp=n%nn;
      for (int i=1;i<=nn;++i)
      {
          
          string::size_type aa=i%l1,bb=i%l2;
          if (aa==0) aa=l1;
          if (bb==0) bb=l2;
          char a=s1[aa-1];
          char b=s2[bb-1];
          if (spr(a,b)==1) ++ansn;
          else 
          if (spr(a,b)==2) ++ansp;
          if (i==pp) {tn=ansn;tp=ansp;}
      }
      printf("%d %d",n/nn*ansp+tp,n/nn*ansn+tn);
}