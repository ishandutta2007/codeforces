#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005];
string s[11];
bool cmp(string u,string p){
	return u<p;
}
int re=1e9,rc[11],cz[11],cs[11],cnt;
void cl(int fr){
	int b[100005];
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		if(abs(b[i]-rc[fr])<cz[fr])b[i]=rc[fr];
	}
	for(int i=1;i<=n;i++){
		if(cs[fr]==0)break;
		if(b[i]==cz[fr]+rc[fr])b[i]=rc[fr],cs[fr]--;
	}
	for(int i=n;i>=1;i--){
		if(cs[fr]==0)break;
		if(b[i]==rc[fr]-cz[fr])b[i]=rc[fr],cs[fr]--;
	}
	for(int i=1;i<=n;i++){
		s[fr]+=char('0'+b[i]);
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
	}
	for(int o=0;o<=9;o++){
		priority_queue<int>q;
		for(int i=1;i<=n;i++)q.push(-abs(a[i]-o));
		int num=0,cha=-1,sum=1;
		for(int i=1;i<=k;i++){
			num+=-q.top();
			if(cha==-q.top())sum++;
			else sum=1,cha=-q.top();
			q.pop();
		}
		if(num<re){
			re=num;
			rc[0]=o;
			cz[0]=cha;
			cs[0]=sum;
			cnt=0;
		}
		if(num==re){
			cnt++;
			rc[cnt]=o;
			cz[cnt]=cha;
			cs[cnt]=sum;
		}
	}
	for(int i=0;i<=cnt;i++){
		cl(i);
	}
	cout<<re<<endl;
	sort(s,s+cnt+1,cmp);
	cout<<s[0];
	return 0;
}