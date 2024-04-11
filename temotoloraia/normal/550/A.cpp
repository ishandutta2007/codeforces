#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define MOD 1e9+7
#define N 100005
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
int AB,BA,ab,ba;
string s;
int main()
{
   cin>>s;
   for (int i=1;i<s.size();i++){
      if (s[i]=='B' && s[i-1]=='A')AB++;
      if (s[i]=='A' && s[i-1]=='B')BA++;
   }
   if (AB==0 || BA==0){cout<<"NO"<<endl;return 0;}
   if (AB+BA>3){cout<<"YES"<<endl;return 0;}
   if (AB+BA==2){
   for (int i=1;i<s.size()-1;i++){
      if (s[i-1]=='A' && s[i]=='B' && s[i+1]=='A'){cout<<"NO"<<endl;return 0;}
      if (s[i-1]=='B' && s[i]=='A' && s[i+1]=='B'){cout<<"NO"<<endl;return 0;}
   }
   cout<<"YES"<<endl;
   return 0;
   }
   for (int i=1;i<s.size()-2;i++){
      if (s[i-1]=='A' && s[i]=='B' && s[i+1]=='A' && s[i+2]=='B'){cout<<"NO"<<endl;return 0;}
      if (s[i-1]=='B' && s[i]=='A' && s[i+1]=='B' && s[i+2]=='A'){cout<<"NO"<<endl;return 0;}
   }
   cout<<"YES"<<endl;
   return 0;
}