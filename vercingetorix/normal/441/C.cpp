#include <iostream>
#include <vector>

using namespace std;

int nextx(int x, int y, int m, int n){
	if((y==m)&&(x%2==1)) return (x+1);
	if((y==1)&&(x%2==0)) return(x+1);
	else return x;
}

int nexty(int x, int y, int m, int n){
	if((y==m)&&(x%2==1)) return (y);
	if((y==1)&&(x%2==0)) return(y);
	if(x%2==1) return (y+1);
	else return (y-1);
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
int n,m,k;
cin >> n >> m>> k;

int xn, yn, x, y;
x=1; y=1;
for(int i=0; i<k-1; i++){
	cout << 2 << " ";
	cout<<x<<" "<<y<<" ";
	xn=nextx(x,y,m,n);
	yn=nexty(x,y,m,n);
	cout<<xn<<" "<<yn<<" ";
	x=nextx(xn,yn,m,n);
	y=nexty(xn,yn,m,n);
	cout <<"\n";
}
cout<< m*n-2*k+2 << " ";
for(int i=0; i< m*n-2*k+2; i++){
	cout<<x<<" "<<y<<" ";
	xn=nextx(x,y,m,n);
	yn=nexty(x,y,m,n);
	x=xn; y=yn;
}


//for(int yu=0; yu<25; yu++) cout<< cards[yu];


}