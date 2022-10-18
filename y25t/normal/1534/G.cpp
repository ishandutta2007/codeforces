#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define N 800005

int n;
std::pair<int,int> a[N];

std::priority_queue<int> L,R;

int t;

ll ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]={x+y,x};
	}
	std::sort(a+1,a+n+1);
	L.push(a[1].sec),R.push(-a[1].sec);
	for(int i=2;i<=n;i++){
		t+=a[i].fir-a[i-1].fir;
		int l=L.top(),r=-R.top()+t,x=a[i].sec;
		if(x<l){
			L.pop();
			R.push(-l+t);
			L.push(x),L.push(x);
			ans+=l-x;
		}
		else if(x>r){
			R.pop();
			L.push(r);
			R.push(-x+t),R.push(-x+t);
			ans+=x-r;
		}
		else
			L.push(x),R.push(-x+t);
	}
	printf("%lld\n",ans);
}