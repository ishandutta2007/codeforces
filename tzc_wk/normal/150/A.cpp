#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,k,ans=1;
void check(){
    int y=x;
	for(int i=2;i*i<=x;i++){
		while(x%i==0&&i*i<=x){
			k++;
			ans*=i;
			x/=i;
			if(k==2&&x!=y){
				k++;return;
			}
		}
    }
    k+=x!=y;
}
signed main(){
	cin>>x;
	check();
	if(k==2)	puts("2");
	else{
		puts("1");
		if(ans==1)	cout<<"0"<<endl;
		else		cout<<ans<<endl;
	}
	return 0;
}