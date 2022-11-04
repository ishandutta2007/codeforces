#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y,z,k,ans;
void pd(int d,int x,int y,int z){if (y+z>x)return;d=min(d,x-y-z);ans+=(d+1)*(d+2)/2;}
signed main(){
	ios::sync_with_stdio(false);
	cin>>x>>y>>z>>k;for (int i=0;i<=k;i++)pd(k-i,x+i,y,z),pd(k-i,y+i,x,z),pd(k-i,z+i,x,y);
	cout<<(k+3)*(k+2)*(k+1)/6-ans<<endl;
}