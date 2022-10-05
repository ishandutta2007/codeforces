#include<bits/stdc++.h>
using namespace std;
int n;
int a[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int h,now=2,cnt=1;
		for(h=1;;h++){
			int o=0;
			if(now>n)break;
			int cc=1;
			for(;;now++){
				if(now>n||cc>cnt)break;
				if(a[now]>a[now+1])cc++;
				o++;
			}
			cnt=o;
		}
		cout<<h-1<<endl;
	}
	return 0;
}