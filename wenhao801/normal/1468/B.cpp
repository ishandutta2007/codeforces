#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define ll long long
const ll S=2e5+6;
using namespace std;
ll n,m;
ll cnt=0;
ll a[S],q[S],qz[S],ans[S];
ll ys[S];
struct node{
	ll st,ed,id;
	double owe;
}section[S*30];
bool operator<(node a,node b){
	return a.owe<b.owe;
}
priority_queue <node> que,g;
void merge(ll upd,ll id1,ll id2){
	que.pop();
	if(id2)
		g.push(section[id2]);
	cnt+=1;
	section[cnt].st=section[id1].st;
	section[cnt].id=cnt;
	section[cnt].ed=section[id2].ed;
	section[cnt].owe=(double)(1.0*qz[section[cnt].ed]-qz[section[cnt].st-1])/(section[cnt].ed-section[cnt].st+1);
	//printf("----???%lf\n",section[cnt].owe);
	ys[section[cnt].st]=cnt;
	if(section[cnt].ed!=n){
		que.push(section[cnt]);
		//printf("PUSH");
	}	
	//printf("%lld %lld\n",section[cnt].st,section[cnt].ed);
	ans[upd]=max(ans[upd],section[cnt].ed-section[cnt].st+1);
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&q[i]);
	}
	
	ll lst=0;
	bool f=0;
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
		if(qz[i]-qz[lst]<=q[m]*(i-lst)){
			cnt+=1;
			section[cnt].st=lst+1,section[cnt].ed=i,section[cnt].owe=(double)(1.0*qz[i]-qz[lst])/(i-lst);
			section[cnt].id=cnt;
			if(section[cnt].ed!=n){
				que.push(section[cnt]);
				//printf("%lld %lld %lf\n",section[cnt].st,section[cnt].ed,section[cnt].owe);
			}
			ys[lst+1]=cnt;
			ans[m]=max(ans[m],i-lst);
			lst=i;
			f=1;
		}
	}
	if(!f)ans[m]=n;
	
	for(int i=m-1;i>=1;i--){
		//printf("------------------%d\n",i);
		ans[i]=ans[i+1];
		ll tp;
		while(1){
			if(que.size())tp=que.top().id;
			else break;
			
			if((g.size())&&tp==g.top().id){
				que.pop();
				g.pop();
				continue;
			}
			//printf("%lld %lld %lld----\n",section[tp].st,section[tp].ed,qz[section[tp].ed]-qz[section[tp].st-1]);
			if(q[i]*(section[tp].ed-section[tp].st+1)<qz[section[tp].ed]-qz[section[tp].st-1]){
				merge(i,tp,ys[section[tp].ed+1]);
				
			}
			else{
				break;
			}
			
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]-1);
	}
	printf("\n");
	return 0;
}