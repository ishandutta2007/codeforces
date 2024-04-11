#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,a[N],l1[N],r1[N],l2[N],r2[N],ans[N];
set<pair<int,int> > S1,S2;
vector<pair<int,int> > IS1[N],IS2[N];
vector<pair<int,int> > ES1[N],ES2[N];
int main(){
	scanf("%d%*d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d%d%d",&a[i],&l1[i],&r1[i],&l2[i],&r2[i]);
	S1.insert(pair<int,int>(0,0));
	S2.insert(pair<int,int>(0,0));
	for (int i=1;i<=n;i++){
		pair<int,int> info;
		bool f1=(l1[i]<=a[i]&&a[i]<=r1[i]);
		bool f2=(l2[i]<=a[i]&&a[i]<=r2[i]);
		bool ff1=f1&(l2[i]<=a[i-1]&&a[i-1]<=r2[i])&(!S2.empty());
		bool ff2=f2&(l1[i]<=a[i-1]&&a[i-1]<=r1[i])&(!S1.empty()); 
		
		for (;!S1.empty();){
			info=*S1.begin();
			if (info.first<l2[i]||!f1){
				ES1[i].push_back(info);
				S1.erase(info);
			}
			else break;
		}
		for (;!S1.empty();){
			info=*S1.rbegin();
			if (info.first>r2[i]||!f1){
				ES1[i].push_back(info);
				S1.erase(info);
			}
			else break;
		}
		
		for (;!S2.empty();){
			info=*S2.begin();
			if (info.first<l1[i]||!f2){
				ES2[i].push_back(info);
				S2.erase(info);
			}
			else break;
		}
		for (;!S2.empty();){
			info=*S2.rbegin();
			if (info.first>r1[i]||!f2){
				ES2[i].push_back(info);
				S2.erase(info);
			}
			else break;
		}
		
		//cout<<S1.size()<<' '<<S2.size()<<endl;
		
		info=pair<int,int>(a[i-1],i);
		if (ff1){
			S1.insert(info);
			IS1[i].push_back(info);
		}
		if (ff2){
			S2.insert(info);
			IS2[i].push_back(info);
		}
	}
	if (S1.empty()&&S2.empty()){
		puts("No");
		return 0;
	}
	puts("Yes");
	int side=0,T=0;
	if (!S1.empty()){
		side=0;
		T=(*S1.begin()).second;
	}
	if (!S2.empty()){
		side=1;
		T=(*S2.begin()).second;
	}
	for (int i=n;i>=1;i--){
		//cout<<T<<' '<<side<<' '<<i<<endl;
		ans[i]=side;
		for (auto j:IS1[i]) S1.erase(j);
		for (auto j:IS2[i]) S2.erase(j);
		for (auto j:ES1[i]) S1.insert(j);
		for (auto j:ES2[i]) S2.insert(j);
		if (T==i){
			if (side==1){
				assert(!S1.empty());
				T=(*S1.begin()).second;
			}
			if (side==0){
				assert(!S2.empty());
				T=(*S2.begin()).second;
			}
			side^=1;
		}
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]); 
	
}