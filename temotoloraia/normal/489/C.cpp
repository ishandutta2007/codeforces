#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define MOD 1e9+7
#define N 100005
using namespace std;
int m,s,ss,a[1000],b[1000];
int main()
{
   cin>>m>>s;
   if (m==1 && s==0){cout<<"0 0"<<endl;return 0;}
   if (s>9*m || s==0){cout<<"-1 -1"<<endl;return 0;}
   ss=s;
   for (int i=1;i<=m&&s;i++){
      if (s>=9){
         b[i]=9;
         s-=9;
      }
      else {
         b[i]=s;
         s=0;
      }
   }
   s=ss;
   s--;
   a[1]=1;
   for (int i=m;i>1 && s;i--){
      if (s>=9){
         a[i]=9;
         s-=9;
      }
      else {
         a[i]=s;
         s=0;
      }
   }
   if (s)a[1]+=s;
   for (int i=1;i<=m;i++)cout<<a[i];
   cout<<" ";
   for (int i=1;i<=m;i++)cout<<b[i];
   return 0;
}