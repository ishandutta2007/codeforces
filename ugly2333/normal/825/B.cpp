//CF 825B
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
int a[11][11];
int main()
{
	int n,i,j,k,s;
	char c;
	n=10;
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=n;j=j+1){
			cin>>c;
			if(c=='X')
				a[i][j]=1;
			if(c=='O')
				a[i][j]=-10;
		}
	}
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=6;j=j+1){
			s=0;
			for(k=0;k<5;k=k+1)
				s+=a[i][j+k];
			if(s>=4){
				cout<<"YES\n";
				return 0;
			}
		}
	}
	for(j=1;j<=n;j=j+1){
		for(i=1;i<=6;i=i+1){
			s=0;
			for(k=0;k<5;k=k+1)
				s+=a[i+k][j];
			if(s>=4){
				cout<<"YES\n";
				return 0;
			}
		}
	}
	for(i=1;i<=6;i=i+1){
		for(j=1;j<=6;j=j+1){
			s=0;
			for(k=0;k<5;k=k+1)
				s+=a[i+k][j+k];
			if(s>=4){
				cout<<"YES\n";
				return 0;
			}
		}
	}
	
	for(i=5;i<=10;i=i+1){
		for(j=1;j<=6;j=j+1){
			s=0;
			for(k=0;k<5;k=k+1)
				s+=a[i-k][j+k];
			if(s>=4){
				cout<<"YES\n";
				return 0;
			}
		}
	}
	
	cout<<"NO\n";
	return 0;
}