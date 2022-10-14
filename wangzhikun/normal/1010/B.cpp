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
int m,n;
int main() {
	cin>>m>>n;
	int actu[60] = {0};
	for(int i=0;i<n;i++){
		cout<<1<<endl;
		cout<<flush;
		cin>>actu[i];
		if(actu[i] == 0)return 0;
	}
	int l = 0,r = m,cnt = 0;
	while(r-l>1){
		int mid = (l+1+r)/2;
		cout<<mid<<endl;
		cout<<flush;
		int cur;
		cin>>cur;
		cur*=actu[cnt];
		if(cur == 0)return 0;
		if(cur == 1){
			l = mid;
		}else{
			r = mid-1;
		}
		cnt+=1;
		cnt%=n;
	}
	cout<<r<<endl;
	cout<<flush;
	return 0;
}