#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const ll MOD=1e9+7,N=2105;
const ll INF=1e11;
string s,ss;
char ch;
int a[5],m[10],x,y,z,np,xx;
int main(){
   for (int i=0;i<10;i++){
      s='0'+i;
      s=s+s+s+s;
      cout<<s<<endl;
      fflush(stdout);
      cin>>x>>y;
      if (x)
	  a[++np]=i;
	  else
	  xx=i;
	  if (np>=4 && i>=4)break;
   }
   ch='0'+xx;
   s="";
   for (int i=0;i<4;i++)s+=ch;
   for (int i=1;i<=4;i++){
      for (int j=0;j<4;j++)
      if (s[j]==ch){
         ss=s;
         s[j]=a[i]+'0';
         cout<<s<<endl;
         fflush(stdout);
         cin>>x>>y;
         if (x==4)return 0;
         if (x==z)
         s=ss;
         else {
         	z++;
         	break;
		 }
      }
   }
   return 0;
}