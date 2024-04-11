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
const int MOD=1e9+7,N=1005;
const ll INF=1e11;

int n, b, g, r;
string s;
int main()
{
   cin>>n>>s;
   for (int i=0;i<n;i++){
      if (s[i]=='B')b++;
      else if (s[i]=='G')g++;
      else r++;
   }
   if (b&&g&&r){cout<<"BGR"<<endl;return 0;}
   if (b==0&&g==0){cout<<"R"<<endl;return 0;}
   if (b==0&&r==0){cout<<"G"<<endl;return 0;}
   if (g==0&&r==0){cout<<"B"<<endl;return 0;}
   if (b==0){
      if (g==1 && r==1){cout<<"B"<<endl;return 0;}
      if (g>1 && r>1){cout<<"BGR"<<endl;return 0;}
      if (g>1){cout<<"BR"<<endl;return 0;}
      if (r>1){cout<<"BG"<<endl;return 0;}
   }
   if (g==0){
      if (b==1 && r==1){cout<<"G"<<endl;return 0;}
      if (b>1 && r>1){cout<<"BGR"<<endl;return 0;}
      if (b>1){cout<<"GR"<<endl;return 0;}
      if (r>1){cout<<"BG"<<endl;return 0;}
   }
   if (r==0){
      if (b==1 && g==1){cout<<"R"<<endl;return 0;}
      if (b>1 && g>1){cout<<"BGR"<<endl;return 0;}
      if (g>1){cout<<"BR"<<endl;return 0;}
      if (b>1){cout<<"GR"<<endl;return 0;}
   }
   return 0;
}