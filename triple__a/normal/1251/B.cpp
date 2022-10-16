#include<bits/stdc++.h>
using namespace std;

bool fg=false;
int q,n,cnt=0;
string s;

int main(){
	cin>>q;
	while (q--){
		cin>>n;
		cnt=0;
		fg=0;
		for (int i=1;i<=n;++i){
			cin>>s;
			int k=s.size();
			if (k&1) fg=1;
			for (int j=0;j<k;++j){
				if (s[j]=='1') cnt++;
			} 
		}
		if (fg||cnt%2==0){
			printf("%d\n",n);
		}
		else{
			printf("%d\n",n-1);
		}
	}
	return 0;
}