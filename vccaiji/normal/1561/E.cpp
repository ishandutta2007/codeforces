#include<bits/stdc++.h>
using namespace std;
int a[10000];
int op[100000];
int cnt=0;
void per(int o){
	op[++cnt]=o;
	for(int i=1;i<=o;i++)if(i<o+1-i)swap(a[i],a[o+1-i]);
}
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		bool r=1;
		for(int i=1;i<=n;i++)if(a[i]%2!=i%2)r=0;
		if(!r){
			cout<<-1<<endl;
			continue;
		}
		cnt=0;
		for(int i=n;i>=3;i-=2){
			for(int j=1;j<=i;j++)if(a[j]==i){
				per(j);
				break;
			}
			for(int j=1;j<=i;j++)if(a[j]==i-1){
				per(j-1);
				per(j+1);
				per(3);
				per(i);
				break;
			}
		}
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++)printf("%d ",op[i]);
		printf("\n");
	}
	return 0;
}