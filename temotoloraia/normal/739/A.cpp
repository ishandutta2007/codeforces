#include <bits/stdc++.h>
using namespace std;
int n,m,x=100005,a,b;
int main() {
   cin>>n>>m;
   while (m--){
      cin>>a>>b;
      x=min(x,b-a+1);
   }
   cout<<x<<endl;
   for (int i=0;i<n;i++)cout<<i%x<<" ";
	return 0;
}