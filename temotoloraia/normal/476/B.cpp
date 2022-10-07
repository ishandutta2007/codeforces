#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define MOD 1e9+7
#define N 100005
#define INF 1e11
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
string s1,s2;
int a1,a2,x;
double ans;
int main()
{
   cin>>s1>>s2;
   for (int i=0;i<s1.size();i++){
      if (s1[i]=='+')a1++;
      if (s2[i]=='+')a2++;
      else if (s2[i]=='?')x++;
   }
   if (a1>=a2 && a2+x>=a1){
      ans=1;
      a1-=a2;
      for (double i=1;i<=a1;i++)ans/=2;
      for (double i=a1+1;i<=x;i++)ans=ans*i/2/(i-a1);
   }
   printf("%.15lf\n",ans);
   return 0;
}