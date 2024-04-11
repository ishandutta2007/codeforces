#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,len[66],res;
string s[66],s1;
unsigned long long sb=1;

int chk(int x){
	int it=0;
	for(auto i:s1){
		if(i==s[x][it]){it++;}
		if(it>=len[x]){
			break;
		}
	}
	return n+len[x]-2*it;
}

int main(){
	for(i=0;i<=63;i++){
		s[i]=to_string(sb);
		len[i]=s[i].size();
		//cout<<s[i]<<endl;
		sb*=2;
	}
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s1;
		n=s1.size();
		res=114514;
		for(i=0;i<=63;i++){
			res=min(res,chk(i));
		}
		cout<<res<<endl;
	}
}