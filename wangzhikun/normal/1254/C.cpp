#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int qlr(int i,int j,int k){// 1 if j is on the right
	cout<<2<<' '<<i<<' '<<j<<' '<<k<<endl;
	cout.flush();
	int ret;
	cin>>ret;
	return ret;
}

ll qsz(int i,int j,int k){
	cout<<1<<' '<<i<<' '<<j<<' '<<k<<endl;
	cout.flush();
	ll ret;
	cin>>ret;
	return ret;
}

int main() {
	int n;
	cin>>n;
	int a = 1,b = 2;
	for(int i=3;i<=n;i++){
		if(qlr(a,b,i) == -1){
			b = i;
		}
	}
	vector< pair<ll,int> > cv;
	for(int i=2;i<=n;i++){
		if(i!=b){
			cv.push_back(make_pair(qsz(a,b,i),i));
		}
	}
	sort(cv.begin(),cv.end());
	vector<int> q1;
	vector<int> q2;
	q1.push_back(a);
	q1.push_back(b);
	int la = b;
	for(int i=0;i<cv.size()-1;i++){
		if(qlr(cv[i].second,la,cv[i+1].second) == 1){
			q2.push_back(cv[i].second);
		}else{
			q1.push_back(cv[i].second);
		}
	}
	q1.push_back(cv[cv.size()-1].second);
	cout<<"0 ";
	for(int i=0;i<q1.size();i++){
		cout<<q1[i]<<' ';
	}
	for(int i=q2.size()-1;i>=0;i--){
		cout<<q2[i]<<' ';
	}
	cout<<endl;
	return 0;
}