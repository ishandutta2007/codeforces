#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1050;
bool test=0;
int per[N],qct;
int Ask(vector<int> v){
	if(test){
		int sum=0;qct++;
		for(int i:v)sum+=per[i];
		return sum%v.size()==0;
	}else{
		if(v.size()==1)return 1;
		printf("? %i ",v.size());
		for(int i:v)printf("%i ",i);
		printf("\n");
		fflush(stdout);
		int t;scanf("%i",&t);
		return t;
	}
}
vector<int> Make(vector<int> v,int x){
	vector<int> ans;
	for(int i:v)if(i!=x)ans.pb(i);
	return ans;
}
int val[N],pos[N],rem[N],n;
void Find(int l,int r,int mod){
	vector<int> alv;
	for(int i=1;i<=n;i++)if(!val[i])alv.pb(i);
	for(int i=1;i<=n;i++)if(!val[i] && rem[i]==l%mod && Ask(Make(alv,i))){val[i]=l;pos[l]=i;break;}
	for(int i=1;i<=n;i++)if(!val[i] && rem[i]==r%mod && Ask(Make(alv,i))){val[i]=r;pos[r]=i;break;}
}
int main(){
	scanf("%i",&n);
	if(test){
		for(int i=1;i<=n;i++)per[i]=i;
		random_shuffle(per+1,per+1+n);
		if(per[1]>n/2)for(int i=1;i<=n;i++)per[i]=n+1-per[i];
		for(int i=1;i<=n;i++)printf("%i ",per[i]);printf("\n");
	}
	Find(1,n,1);
	for(int i=1;i<=n;i++)if(!val[i])rem[i]=Ask({pos[1],i});
	int mod=2;
	for(int i=2;i<=n/2;i++){
		Find(i,n-i+1,mod);
		if(i==mod*2){
			for(int j=1;j<=n;j++)if(!val[j]){
				int go=(mod*(2*mod+1)+rem[j]+mod)%(2*mod);
				if(!go)go=2*mod;
				vector<int> v;
				for(int k=1;k<=2*mod;k++)if(k!=go)v.pb(pos[k]);
				v.pb(j);
				if(Ask(v))rem[j]+=mod;
			}
			mod*=2;
		}
	}
	if(val[1]>n/2)for(int i=1;i<=n;i++)val[i]=n+1-val[i];
	printf("! ");for(int i=1;i<=n;i++)printf("%i ",val[i]);printf("\n");
	fflush(stdout);
	if(test){
		for(int i=1;i<=n;i++)assert(val[i]==per[i]);
		printf("Q: %i\n",qct);
	}
	return 0;
}