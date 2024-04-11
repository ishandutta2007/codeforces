#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	if(__builtin_popcount(n)<=k&&n>=k){
		puts("YES");
		vector<int> kk;
		int tot=0;
		for(int i=0;i<=(int)log2(n);i++){
			if(n>>i&1){
				kk.push_back(1);
				tot++;
			}
			else	kk.push_back(0);
		}
		tot=k-tot;
		int lt=k-kk.size();
		vector<int> ans;
		for(int i=kk.size()-1;i>0;i--){
//			cout<<"tot:"<<tot<<"\t";
//			for(int j=0;j<kk.size();j++)cout<<kk[j]<<" ";
//			cout<<endl;
			if(tot==0)	break;
			int sub=min(kk[i],tot);
			kk[i-1]+=2*sub;
			kk[i]-=sub;
			tot-=sub;
		}
		for(int i=0;i<kk.size();i++){
			for(int j=0;j<kk[i];j++){
				ans.push_back(1<<i);
			}
		}
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
	}
	else	puts("NO");
	return 0;
}
//