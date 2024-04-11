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
int t, a, b, p;
string s;
vector<int>v;
int main()
{
   cin>>t;
   while (t--){
      cin>>s;
      v.clear();
      for (a=1;a<=12;a++)
      if(12%a==0){
         b=12/a;
         for (int i=0;i<b;i++){
            p=1;
            for (int j=i;j<12;j+=b)
            if (s[j]=='O')
            p=0;
            if (p==1)break;
         }
         if (p)v.push_back(a);
      }
      cout<<v.size()<<" ";
      for (int i=0;i<v.size();i++)cout<<v[i]<<"x"<<12/v[i]<<" ";
      cout<<endl;
   }
   return 0;
}