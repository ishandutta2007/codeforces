#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<cstring>
using namespace std;
#define N 300010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define CL(x) memset(x,0,sizeof(x))

struct Dat{
	LL ind,c;
	bool operator<(Dat y)const{return this->c<y.c;}
};
int n,k,ans[N];
LL tot=0;

int main(){
	scanf("%d%d",&n,&k);
	priority_queue<Dat> heap0;
	rep(i,1,n){
		int x;
		scanf("%d",&x);
		heap0.push(Dat{i,x});
		if(i>k){
			Dat y=heap0.top();
			tot+=y.c*(i-y.ind);ans[y.ind]=i;
			heap0.pop();
		}
	}
	rep(i,1,k){
		Dat y=heap0.top();
		tot+=y.c*(i+n-y.ind);ans[y.ind]=i+n;
		heap0.pop();
	}
	cout<<tot<<endl;
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}