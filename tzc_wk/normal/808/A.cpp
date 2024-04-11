#include <bits/stdc++.h>
using namespace std;
int n,a[11],cnt,ans;
int main(){
	cin>>n;
	int tmpn=n;
	while(tmpn){
		a[++cnt]=tmpn%10;
		tmpn/=10;
	}
	reverse(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++){
		if(a[i]){
			ans=a[i]+1;
            for(int j=cnt;j>i;j--)	ans*=10;
			break;
		}
	}
	cout<<ans-n<<endl;
	return 0;
}