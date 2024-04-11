#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int n,m;scanf("%i%i",&n,&m);
	string s[n];
	int a[m];
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<m;i++)scanf("%i",&a[i]);
	vector<string> all;
	for(int i=0;i<m;i++)all.pb((string)s[a[i]-1]);
	sort(all.begin(),all.end());
	//cout<<all[0]<<" "<<all[m-1]<<endl;
	if((int)all[0].size()!=(int)all[m-1].size())return 0*printf("No");
	int sz=(int)all[0].size();
	string ans=all[0];
	//for(int i=0;i<sz;i++)ans[i]=all[0][i];
	for(int i=0;i<sz;i++){
		for(string x:all){
			if(ans[i]!=x[i])ans[i]='?';
		}
	}
	bool take[n];
	memset(take,false,sizeof(take));
	for(int i=0;i<m;i++)take[a[i]-1]=true;
	for(int i=0;i<n;i++){
		bool ok=true;
		if((int)s[i].size()!=sz)ok=false;
		for(int j=0;j<sz;j++){
			if(ans[j]!='?'&&ans[j]!=s[i][j])ok=false;
		}
		if(ok!=take[i])return 0*printf("No");
	}
	cout<<"Yes\n"<<ans;
	return 0;
}