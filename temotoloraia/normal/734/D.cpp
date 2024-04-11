#include <bits/stdc++.h>
using namespace std;
int n,x,y,a,b;
char ch;
int ans[9],dis[9];
int main() {
   cin>>n>>x>>y;
   for (int i=1;i<=8;i++)dis[i]=2000000005;
   while (n--){
      cin>>ch>>a>>b;
      if (b==y && a>x && a-x<dis[1]){
         dis[1]=a-x;
         if (ch=='R' || ch=='Q')ans[1]=1;
         else ans[1]=0;
      }
      if (b-y==a-x && a>x && a-x<dis[2]){
         dis[2]=a-x;
         if (ch=='B' || ch=='Q')ans[2]=1;
         else ans[2]=0;
      }
      if (b>y && a==x && b-y<dis[3]){
         dis[3]=b-y;
         if (ch=='R' || ch=='Q')ans[3]=1;
         else ans[3]=0;
      }
      if (b-y==x-a && a<x && b-y<dis[4]){
         dis[4]=b-y;
         if (ch=='B' || ch=='Q')ans[4]=1;
         else ans[4]=0;
      }
      if (b==y && a<x && x-a<dis[5]){
         dis[5]=x-a;
         if (ch=='R' || ch=='Q')ans[5]=1;
         else ans[5]=0;
      }
      if (b-y==a-x && a<x && x-a<dis[6]){
         dis[6]=x-a;
         if (ch=='B' || ch=='Q')ans[6]=1;
         else ans[6]=0;
      }
      if (b<y && a==x && y-b<dis[7]){
         dis[7]=y-b;
         if (ch=='R' || ch=='Q')ans[7]=1;
         else ans[7]=0;
      }
      if (y-b==a-x && a>x && a-x<dis[8]){
         dis[8]=a-x;
         if (ch=='B' || ch=='Q')ans[8]=1;
         else ans[8]=0;
      }
   }
   for (int i=1;i<=8;i++)
   if (ans[i]){
      cout<<"YES"<<endl;
      return 0;
   }
   cout<<"NO"<<endl;
	return 0;
}