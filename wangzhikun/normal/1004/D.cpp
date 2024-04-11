// Author : WangZhikun
// 2018.7.6

#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,a[1000010] = {0},c[1000010] = {0},cur,ans = 0;
ll b[100],fin = 0;

void testans(ll x,ll y,ll x1,ll y1){
	if(fin)return;
	memset(c,0,sizeof(c));
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			c[abs(i-x1)+abs(j-y1)]+=1;
		}
	}
	for(int j=1;j<=1000005;j++)if(c[j]!=a[j])return;
	fin = 1;
	cout<<x<<' '<<y<<endl<<x1<<' '<<y1<<endl;
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cur;
		a[cur]+=1;
	}
	if(n == 1 && a[0] == 1){
		testans(1,1,1,1);
	}
	a[0] = 0;
	ll cnv = 0,cnt = 0,cnf = 0,qk,tqk = 0,nqk;
	for(int j=1;j<=1000005;j++){
		if(a[j]!=a[j-1]+4-2*tqk){
			nqk = a[j-1]+4-2*tqk-a[j];
			//cout<<j<<' '<<nqk<<endl;
			if(nqk<0)break;
			for(int k=0;k<nqk;k++){
				b[tqk+k] = j-1;
			}
			tqk+=nqk;
			if(tqk>=3)break;
		}
	}
	//cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<endl;
	for(int j=1;j<=1000005;j++){
		if(a[j]!=j*4){
			qk = j*4-a[j];
			cnv = j-1;
			break;
		}
	}
	for(int j=1;j<=1000005;j++){
		if(a[j]==0){
			cnt = a[j-1];
			cnf = j-1;
			break;
		}
	}
	if(cnt == 1){
		for(int i=0;i<=cnf;i++){
			if((b[0]+1+i)*(b[1]+1+cnf-i) == n){
				testans(b[0]+1+i,b[1]+1+cnf-i,1+b[0],1+b[1]);
				testans(b[0]+1+i,b[1]+1+cnf-i,1+b[1],1+b[0]);
			}
			if((b[2]+1+i)*(b[1]+1+cnf-i) == n){
				testans(b[2]+1+i,b[1]+1+cnf-i,1+b[2],1+b[1]);
				testans(b[2]+1+i,b[1]+1+cnf-i,1+b[1],1+b[2]);
			}if((b[0]+1+i)*(b[2]+1+cnf-i) == n){
				testans(b[0]+1+i,b[2]+1+cnf-i,1+b[0],1+b[2]);
				testans(b[0]+1+i,b[2]+1+cnf-i,1+b[2],1+b[0]);
			}
		}
	}
	if(cnt == 2){
		testans((b[0]*2+1),n/(b[0]*2+1),b[0]+1,cnf-b[0]+1);
		testans((b[1]*2+1),n/(b[1]*2+1),b[1]+1,cnf-b[1]+1);
		testans((b[2]*2+1),n/(b[2]*2+1),b[2]+1,cnf-b[2]+1);
		testans((b[1]*2+1),n/(b[1]*2+1),b[1]+1,b[0]+1);
		testans((b[1]*2+1),n/(b[1]*2+1),b[1]+1,b[2]+1);
		testans((b[0]*2+1),n/(b[0]*2+1),b[0]+1,b[1]+1);
		testans((b[0]*2+1),n/(b[0]*2+1),b[0]+1,b[2]+1);
		testans((b[2]*2+1),n/(b[2]*2+1),b[2]+1,b[1]+1);
		testans((b[2]*2+1),n/(b[2]*2+1),b[2]+1,b[0]+1);
	}
	if(cnt == 4 || cnt == 2){
		testans((cnv*2+1),n/(cnv*2+1),cnv+1,(n/(cnv*2+1)+1)/2);
	}
	if(!fin){
		cout<<-1<<endl;
	}
	return 0;
}