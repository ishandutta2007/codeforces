// author: xay5421
// created: Mon Jun 14 13:49:25 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=800005;
int n,x[N],y[N],id[N];
priority_queue<LL>q1; // max-heap
priority_queue<LL,vector<LL>,greater<LL> >q2; // min-heap
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int x_,y_;
		scanf("%d%d",&x_,&y_);
		x[i]=(x_-y_);
		y[i]=(x_+y_);
		id[i]=i;
	}
	sort(id+1,id+1+n,[&](int k1,int k2){return y[k1]<y[k2];});
	LL ans=0;
	q1.push(-1e18),q2.push(1e18);
	rep(_,1,n){
		LL x_=x[id[_]],y_=y[id[_]];
		if(x_>=q1.top()-y_&&x_<=q2.top()+y_){
			q1.push(x_+y_);
			q2.push(x_-y_);
		}else if(x_>q2.top()+y_){
			ans+=x_-(q2.top()+y_);
			q2.push(x_-y_);
			q2.push(x_-y_);
			q1.push(q2.top()+y_*2);
			q2.pop();
		}else{
			assert(x_<q1.top()-y_);
			ans+=q1.top()-y_-x_;
			q1.push(x_+y_);
			q1.push(x_+y_);
			q2.push(q1.top()-y_*2);
			q1.pop();
		}
	}
	printf("%lld\n",ans/2);
	return 0;
}