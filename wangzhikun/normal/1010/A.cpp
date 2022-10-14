// Author : WangZhikun
// Date   : 2018.07.26

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int ans = 1;
void opyn(){if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;}
int n;
double m,sm,a[2020];
int main() {
	cin>>n>>m;
	sm = m;
	for(int i=0;i<n;i++){
		cin>>a[i*2]>>a[((i-1+n)%n)*2+1];
	}
	int inp = 0;
	for(int i=n*2-1;i>=0;i--){
		if(a[i] == 1){
			inp = 1;
			break;
		}
		m = m*(a[i]/(a[i]-1));
	}
	if(inp){
		cout<<-1<<endl;
	}else{
		printf("%.8f",m-sm);
	}
	return 0;
}