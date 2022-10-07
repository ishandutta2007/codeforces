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
int n, c[N];
ll dpy[N], dpn[N];
string s[N],ss[N];
string f (string str)
{
   string sss;
   for (int i=str.size()-1;i>=0;i--)sss+=str[i];
   return sss;
}
int main()
{
   cin>>n;
   for (int i=1;i<=n;i++)cin>>c[i];
   for (int i=1;i<=n;i++){
      cin>>s[i];
      ss[i]=f(s[i]);
   }
   dpy[1]=c[1];
   dpn[1]=0;
   for (int i=2;i<=n;i++){
      dpy[i]=-1;
      dpn[i]=-1;
      
      
      if (s[i]>=s[i-1] && dpn[i-1]!=-1)
      dpn[i]=dpn[i-1];
      if (s[i]>=ss[i-1] && dpy[i-1]!=-1)
      if (dpn[i]==-1 || dpn[i]>dpy[i-1])
      dpn[i]=dpy[i-1];
      
      
      if (ss[i]>=s[i-1] && dpn[i-1]!=-1)
      dpy[i]=dpn[i-1]+c[i];
      if (ss[i]>=ss[i-1] && dpy[i-1]!=-1)
      if (dpy[i]==-1 || dpy[i]>dpy[i-1]+c[i])
      dpy[i]=dpy[i-1]+c[i];
   }
   if (dpy[n]!=-1 && dpn[n]!=-1)cout<<min(dpy[n],dpn[n])<<endl;
   else cout<<dpy[n]+dpn[n]+1<<endl;
   return 0;
}