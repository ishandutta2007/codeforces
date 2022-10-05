#include <bits/stdc++.h>
using namespace std;
int n;
int a[16];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=0;i<(1<<n);i++){
		int tmp=0;
		for(int j=0;j<n;j++){
			if(i>>j&1)	tmp+=a[j];
			else	tmp-=a[j];
		}
		if((tmp+36000)%360==0){
			puts("YES");
			exit(0);
		}
	}
	puts("NO");
	return 0;
}