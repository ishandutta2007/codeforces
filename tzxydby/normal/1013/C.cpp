#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int inf=1<<30;
int num[200020];
inline int read(){
    char ch=' ';
	int x=0;
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}

signed main(){
	int n;
	cin>>n;
	for(int i=0;i<2*n;i++)cin>>num[i];
	sort(num,num+2*n);
	int x=num[n-1]-num[0];
	int y=num[2*n-1]-num[n];
	int ans=x*y;
	int a1=num[n+n-1]-num[0];
	for(int i=0;i<n;i++){
		//cout<<a1*(num[i+n]-num[i+1])<<endl;
		if((long long)a1*(num[i+n]-num[i+1])<ans)ans=a1*(num[i+n]-num[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}