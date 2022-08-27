#include <iostream>
#include <vector>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
 int m,n;
 
 int x,y;
 cin >> n >> m;
 //n=50;
 //m=49;
 long long dang=1;
 int* c= new int[n];
 for(int k=0; k<n; k++) c[k]=k;
 
 for(int i=0; i<m; i++){
	cin >> x >> y;
	//x=i+1; y=i+2;
	x--;
	y--;
	int a=c[x];
	int b=c[y];
	if(a!=b){
		for(int l=0; l<n; l++){
			if(c[l]==b) c[l]=a;
		}
		dang*=2;
	}
}

cout << dang;

  return 0;
}