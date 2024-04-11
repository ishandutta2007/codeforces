#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
int n,a[N],b[N],cnt[N],mu[N];
ll ans;
vector<int>d[N];
int coprime(int k1){
	int k3=0;
	for(auto k2:d[k1])k3+=mu[k2]*cnt[k2];
	return k3;
}
void update(int k1,int k2){
	for(auto k3:d[k1])cnt[k3]+=k2;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[a[i]]=1,ans=max(ans,(ll)a[i]);
	for(int i=1;i<N;++i){
		for(int j=i;j<N;j+=i)d[j].push_back(i);
		if(i==1)mu[i]=1;
		else if((i/d[i][1])%d[i][1]==0)mu[i]=0;
		else mu[i]=-mu[i/d[i][1]];
	}
	for(int d=1;d<N;++d){
//		printf(">>> %d\n",d);
		stack<int>st;
		for(int i=(N-1)/d;i>=1;--i){
			if(b[i*d]==0)continue;
//			printf("!!! %d\n",i);
			while(coprime(i)){
				ans=max(ans,1ll*i*st.top()*d);
				update(st.top(),-1);
				st.pop();
			}
			update(i,1);
			st.push(i);
		}
		while(!st.empty()){
			update(st.top(),-1);
			st.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}