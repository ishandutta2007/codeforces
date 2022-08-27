#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int lowbit(int x){
	int y=x;
	int a=1;
	while(y%2==0){
		y/=2;
		a*=2;
	}
	return a;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
 
  int s,l;
int ans=0;
  cin >> s >> l;
  std::vector<int> lb;
  lb.push_back(0);
  int sum=0;
  for(int i=1;i<=l;i++){
	  int x=lowbit(i);
	  lb.push_back(x);
	  sum+=x;
  }
  if(sum<s){
	  cout<<-1;
	  return 0;
  }
  int md=1;
  int sz=l;
  while((2*md)<=l) md*=2;
  std::vector<bool> u(l+1, true);
  while(1){
	  for(int i=md; i<=l; i+=2*md){
		  if((sum-s)<md) break;
		  if(u[i]==true){
			  sum-=md;
			  u[i]=false;
			  sz--;
		  }
	  }
	  if(sum == s) break;
	  md/=2;

  }
  cout << sz<<"\n";
  for(int i=1; i<=l; i++){
	  if(u[i]) cout<<i<<" ";
  }
  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}