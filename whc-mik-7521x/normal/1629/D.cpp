#include<bits/stdc++.h>
using namespace std;
const int NN=100010;
map<string,int>ssss,qwer;
int t,n,len[NN];
string s[NN],kk[NN];
int ed[NN];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)cin>>s[i],len[i]=s[i].size(),kk[i]="";
		bool ok=0;
		ssss.clear(),qwer.clear();
		for(int i=n;i;i--)ssss[s[i]]=i;
		for(int i=1;i<=n;i++){
			for(int j=0;j<len[i];j++)kk[i]+=s[i][len[i]-j-1];
			if(ssss.count(kk[i])){ok=1;break;}
			qwer[kk[i]]=i;
		}
		if(ok){puts("YES");continue;}
		for(int i=1;i<=n;i++){
			if(len[i]!=3)continue;
			string lty="";
			lty+=s[i][0],lty+=s[i][1];
			if(qwer.count(lty)&&qwer[lty]>i){
                ok=1;
                break;
            }
			lty[0]=s[i][2];
			if(ssss.count(lty)&&ssss[lty]<i){
                ok=1;
                break;
            }
		}
		if(ok){
            puts("YES");
            continue;
        }
		puts("NO");
	}
	return 0;
}