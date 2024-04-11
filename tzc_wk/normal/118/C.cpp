#include <bits/stdc++.h>
using namespace std;
const int INF=1e5;
const int MAXN=1e4+100;
int n,k;
string t;
struct node{
	int dist;
	int more,pos;
};
bool cmp(node a,node b){
	if(a.dist!=b.dist)	return a.dist<b.dist;
	else if(a.dist==b.dist&&a.more!=b.more)	return a.more<b.more;
	else if(a.dist==b.dist&&a.more==b.more&&a.pos!=b.pos)	return a.pos<b.pos;
}
int a[MAXN];
int main(){
	cin>>n>>k;
	cin>>t;
	for(int i=0;i<n;i++){
		a[i]=t[i]-'0';
	}
	//cout<<(("dist">"dista")?"ok":"error");
	string pre=t,ansStr="a";
	int ans=INF,cnt=0;
	for(int j=0;j<10;j++){
		pre=t;
		node prio[MAXN];
		cnt=0;
		for(int i=0;i<n;i++){
			node b;
			if(a[i]<j){
				b.dist=j-a[i];
				b.more=1;
				b.pos=-i;
			}
			else{
				b.dist=a[i]-j;
				b.more=0;
				b.pos=i;
			}
			prio[i]=b;
		}
		sort(prio,prio+n,cmp);
		for(int i=0;i<k;i++){
			cnt+=prio[i].dist;
			if(prio[i].more==1){
				pre[-prio[i].pos]=(char)(j+'0');
			}
			else{
				pre[prio[i].pos]=(char)(j+'0');
			}
		}
		if(cnt<ans||(cnt==ans&&pre<ansStr)){
			ans=cnt;
			ansStr=pre;
		}
	}
	cout<<ans<<endl<<ansStr<<endl;
	return 0;
}