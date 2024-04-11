#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 5005;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> a[N];
int n,q,l,r,n1[N];
int n2[N*N];

int main(){
	//freopen("test.in","r",stdin);
	rep(i,0,N-1)a[i].clear();
	
	scanf("%d%d",&n,&q);
	rep(i,1,q){
		scanf("%d%d",&l,&r);
		rep(j,l,r) if(a[j].size()<=2) a[j].PB(i);
	}
	int sum = n, mi = 1e9;
	rep(i,1,n){
		if(a[i].size()==1){
			n1[a[i][0]]++;
		}else if(a[i].size()==2){
			n2[a[i][0]*5000+a[i][1]]++;
		}else if(!a[i].size()){
			sum--;
		}
	}
	rep(i,1,q-1)rep(j,i+1,q){
		mi = min(mi, n1[i]+n1[j]+n2[i*5000+j]);
	}
	cout<<sum-mi<<endl;
	return 0;
}