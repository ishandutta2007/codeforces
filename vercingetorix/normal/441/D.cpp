#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int n,m;
  cin >> n;
  std::vector<int> p(n+2, 0);
  for(int i=1; i<=n; i++){
	  int x;
	  cin>>x;
	  p[i]=x;
  }
  cin>>m;
  std::vector<bool> v(n+2, false);
  int currm=0;
  for(int i=1; i<=n; i++){
	  if(v[i]==false){
		  int k=1;
		  int c=p[i];
		  v[c]=true;
		  while(c!=i){
			  k++;
			  c=p[c];
			  v[c]=true;
		  }
		  currm+=(k-1);

	  }

  }
  cout << abs(currm-m) << "\n";
  while(currm!=m){
	  if(currm>m){
		  int i=1;
		  while(p[i]==i) i++;
		  cout << i <<" ";
		  int jmin=n;
		  int c=p[i];
		  while(c!=i){
			  if(c<jmin) jmin=c;
			  c=p[c];
		  }
		  cout << jmin << " ";
		  int a=p[i];
		  p[i]=p[jmin];
		  p[jmin]=a;
		  currm--;
	  }
	  else{
		  cout << "1 ";
		  for(int i=1;i<=n;i++) v[i]=false;
		  int c=p[1];
		  v[1]=true;
		  while(c!=1){
			  v[c]=true;
			  c=p[c];
		  }
		  int j=1;
		  while(v[j]==true) j++;
		  cout << j << " ";
		  int a=p[1];
		  p[1]=p[j];
		  p[j]=a;
		  currm++;
	  }
  }
  return 0;
}