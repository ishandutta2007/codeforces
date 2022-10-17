#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t,a[2000500],nxt[2000500],no[2000500],t1,t2,t3;
bool b[10000500];
ll res;
int main(){
	ios::sync_with_stdio(0);
	b[1]=1;
	for(i=2;i<=1000000;i++){
		if(!b[i]){
			for(j=i+i;j<=1000000;j+=i){
				b[j]=1;
			}
		}
	}
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(no,0,n*12+50);
		memset(nxt,0,n*12+50);
		res=0;
		for(i=n+1;i<=n+n+n;i++){
			nxt[i]=i;
			no[i]=i;
		}
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=n;i>=1;i--){
			no[i]=no[i+m];
			if(a[i]!=1&&b[a[i]]){
				//printf("NMSL%d\n",i);
				no[i]=i;
			}
			
			nxt[i]=nxt[i+m];
			if(!b[a[i]]){
				nxt[i]=i;
			}
		}
		for(i=1;i<=n;i++){
			if(a[i]!=1&&b[a[i]])continue;
			t1=nxt[i];
			t2=nxt[t1+m];
			t3=no[i];
			
			
			//printf("nmsl%d %d %d\n",t1,t2,t3);
			t2=min(t2,t3);
			t1=max(t1,i+m);
			if(t2<=t1)continue;
			
			
			res+=max(0,(t2-t1)/m);
		}
		
		cout<<res<<'\n';
	}
}