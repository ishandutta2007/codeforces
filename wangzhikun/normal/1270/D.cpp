#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int qn[550];
int retp,retv;
void query(){
	cout<<"? ";
	for(int i=1;i<550;i++){
		if(qn[i])cout<<i<<' ';
	}
	cout<<endl;
	cout.flush();
	cin>>retp>>retv;
}

int n,k;

int main() {
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		qn[i] = 1;
	}
	query();
	int p1 = retp,v1 = retv;
	qn[p1] = 0;
	qn[k+1] = 1;
	query();
	int p2 = retp,v2 = retv;
	if(v2>v1){
		qn[p1] = 1;
		int cnt = 0;
		for(int i=1;i<=k;i++){
			if(qn[i] && i!=p1){
				qn[i] = 0;
				query();
				if(retv>v1)cnt+=1;
				qn[i] = 1;
			}
		}cout<<"! "<<cnt+1<<endl;
	}else{
		
		qn[p1] = 1;
		int cnt = 0;
		for(int i=1;i<=k;i++){
			if(qn[i] && i!=p1){
				qn[i] = 0;
				query();
				if(retv==v1)cnt+=1;
				qn[i] = 1;
			}
		}
		cout<<"! "<<cnt+1<<endl;
	}
	return 0;
}

/*
	Do something instead of doing nothing and stay organized
	Check n == 1, array size , -fsanitize=address, -Wshadow
	Whenever stuck for 15 minutes take a break out
*/
//2 0 1 9