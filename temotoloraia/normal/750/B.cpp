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
const int MOD=1e9+7,N=5000005;
const ll INF=1e11;
int n,t,x,y;
string s;
int main(){
   cin>>n;
   while (n--){
      cin>>t>>s;
      if ((x==0 && s!="South")||(x==20000 && s!="North")||x<0||x>20000){
         cout<<"NO"<<endl;
         return 0;
      }
      if (s=="South")x+=t;
      if (s=="North")x-=t;
   }
   if (x){
      cout<<"NO"<<endl;
      return 0;
   }
   cout<<"YES"<<endl;
   return 0;
}