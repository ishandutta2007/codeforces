#include <iostream>
#include <vector>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
int n,m;
cin >> n >> m;
int *v=new int[n+1];
for(int i=1; i<=n; i++){
	int x;
	cin >>x;
	v[i]=x;
}
int s=0;
for(int j=1;j<=m;j++){
	int k,l;
	cin >> k >> l;
	s+=min(v[k],v[l]);
}
cout<<s;

//for(int yu=0; yu<25; yu++) cout<< cards[yu];


}