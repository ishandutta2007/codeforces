#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500050;
int a[N],b[N];
ll fw[N],bw[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	stack<int> stk;
	stk.push(0);
	ll sum=0;
	for(int i=1;i<=n;i++){
		while(a[stk.top()]>a[i]){
			int j=stk.top();stk.pop();
			sum-=(ll)a[j]*(j-stk.top());
		}
		sum+=(ll)a[i]*(i-stk.top());
		stk.push(i);
		fw[i]=sum;
	}
	reverse(a+1,a+1+n);
	stk=stack<int>();
	stk.push(0);
	sum=0;
	for(int i=1;i<=n;i++){
		while(a[stk.top()]>a[i]){
			int j=stk.top();stk.pop();
			sum-=(ll)a[j]*(j-stk.top());
		}
		sum+=(ll)a[i]*(i-stk.top());
		stk.push(i);
		bw[n-i+1]=sum;
	}
	reverse(a+1,a+1+n);
	ll ans=0;
	int pos=0;
	for(int i=1;i<=n;i++)if(ans<fw[i]+bw[i]-a[i])ans=fw[i]+bw[i]-a[i],pos=i;
	int mn=a[pos];
	for(int i=pos;i<=n;i++)mn=min(mn,a[i]),b[i]=mn;
	mn=a[pos];
	for(int i=pos-1;i>=1;i--)mn=min(mn,a[i]),b[i]=mn;
	for(int i=1;i<=n;i++)printf("%i ",b[i]);
	return 0;
}