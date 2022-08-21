#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m;
string s,t;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d",&n);
	m=4;
	s="aaaa";
	for(i=1;i<10;i++)
	  {
	   for(j=0,k=0;j<m;j++)
	     {
		  t.push_back(s[j]);
		  if(s[j]=='a'+i-1)
		    {
		     k++;
		     if(i<9)
		       {
		        if(k==1)
		          t.push_back('a'+i);
		        if(k%3==1)
		          {
		           t.push_back('a'+i);
		           t.push_back('a'+i);
		           t.push_back('a'+i);
			      }
			   }
			 else
			   if(k%3==1)
			     for(l=1;l<=(n>>k/3*2&3);l++)
		           t.push_back('a'+i);
			}
		 }
	   s=t;
	   t.clear();
	   m=s.size();
	  }
	printf("%s abcdefghij\n",s.c_str());
	return 0;
}