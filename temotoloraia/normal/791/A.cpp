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
const int MOD=1e8,N=25005;
const ll INF=1e17;
int a,b,c;
int main(){
   cin>>a>>b;
   while (a<=b){
      c++;
      a*=3;
      b*=2;
   }
   cout<<c<<endl;
   return 0;
}