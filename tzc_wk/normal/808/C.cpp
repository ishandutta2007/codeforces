#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,id;
	friend bool operator <(node a,node b){
		return a.x>b.x;
	}
} a[105];
int n,w,ans[105];
int main(){
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a[i].x=x;
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans[a[i].id]=(a[i].x+1)/2;
		w-=ans[a[i].id];
	}
	if(w<0)	return puts("-1"),0;
	int cur=1;
	while(w>0){
//		cout<<"w="<<w<<endl;
//		cout<<a[cur].x-ans[a[cur].id]<<endl;
		if(a[cur].x-ans[a[cur].id]>=w){
			ans[a[cur].id]+=w;
			break;
		}
		else{
			w-=a[cur].x-ans[a[cur].id];
			ans[a[cur].id]=a[cur].x;
		}
		cur++;
	}
	for(int i=1;i<=n;i++)	cout<<ans[i]<<" ";
	return 0;
}