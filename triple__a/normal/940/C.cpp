#include "bits/stdc++.h"

using namespace std;

const int maxn=100007;

int main(){
	int n,k,cnt=0;
	char s[maxn];
	int ans[maxn];
	bool al[30];
	int dz[30];
	char zm[30];
	memset(al,0,sizeof(al));
	memset(ans,0,sizeof(ans));
	cin>>n>>k;
	cin>>s;
	for (int i=0;i<n;++i){
		al[s[i]-'a']=1;
	}
	for (int i=0;i<26;++i){
		if (al[i]){
			dz[i]=cnt;
			zm[cnt++]=i+'a';
		}
	}
	if (n<k){
		cout<<s;
		for (int i=1;i<=k-n;++i){
			cout<<zm[0];
		}
	}
	else{
		for (int i=0;i<k;++i){
			ans[i]=dz[s[i]-'a'];
		}
		ans[k-1]++;
		for (int i=k-1;i>-1;--i){
			if (ans[i]>=cnt){
				ans[i]=0;
				ans[i-1]++;
			}
		}
		for (int i=0;i<k;++i){
			cout<<zm[ans[i]];
		}
	}
	return 0; 
}