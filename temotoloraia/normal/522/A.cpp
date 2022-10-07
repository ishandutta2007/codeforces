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
const int MOD=1e9+7,N=100005;
const ll INF=1e11;
int n,ans;
string s="polycarp",s1,s2;
map<string,int>M;
string f(string ss)
{
   string st;
   for (int i=0;i<ss.size();i++)
   if ('A'<=ss[i]&&ss[i]<='Z')
   st+=ss[i]-'A'+'a';
   else
   st+=ss[i];
   return st;
}
int main()
{
   M[s]=1;
   cin>>n;
   while (n--){
      cin>>s1>>s2>>s2;
      s1=f(s1);
      s2=f(s2);
      M[s1]=M[s2]+1;
      ans=max(ans,M[s1]);
   }
   cout<<ans<<endl;
   return 0;
}