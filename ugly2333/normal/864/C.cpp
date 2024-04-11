//CF 864C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int main()
{
	int a,b,f,k,x,y,ans;
	cin>>a>>b>>f>>k;
	x=0;
	y=b;
	ans=0;
	while(k--){
		if(x==0){
			if(y<f){
				cout<<"-1\n";
				return 0;
			}
			if(y>=a+a-f||k==0&&y>=a)
				y-=a;
			else{
				ans++;
				y=b-a+f;
			}
			x=a;
		}
		else{
			if(y<a-f){
				cout<<"-1\n";
				return 0;
			}
			if(y>=a+f||k==0&&y>=a)
				y-=a;
			else{
				ans++;
				y=b-f;
			}
			x=0;
		}
		if(y<0){
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}