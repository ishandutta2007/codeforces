#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
int n,r[N];
int Ask(int a,int b,int c){
	//assert(a>=0&&a<n);
	//assert(b>=0&&b<n);
	//assert(c>=0&&c<n);
	printf("? %i %i %i\n",a+1,b+1,c+1);
	fflush(stdout);
	int x;
	scanf("%i",&x);
	return x;
}
int main(){
	int tt;
	scanf("%i",&tt);
	while(tt--){
		scanf("%i",&n);
		for(int i=0;i<n;i+=3){
			r[i]=Ask(i,i+1,i+2);
		}
		int pos=-1;
		for(int i=0;i<n-4;i+=3){
			if(r[i]!=r[i+3])pos=i;
		}
		assert(pos!=-1);
		assert(pos+4<n);
		r[pos+1]=Ask(pos+1,pos+2,pos+3);
		r[pos+2]=Ask(pos+2,pos+3,pos+4);
		int crw=-1,imp=-1;
		for(int i=0;i<3;i++){
			if(r[pos+i]!=r[pos+i+1]){
				if(r[pos+i]==1)crw=pos+i,imp=pos+i+3;
				else crw=pos+i+3,imp=pos+i;
			}
		}
		assert(crw!=-1&&imp!=-1);
		vector<int> ans(1,imp);
		for(int i=0;i<n;i+=3){
			bool have_a=false;
			for(int j:{i,i+1,i+2}){
				if(j==crw)have_a=true;
			}
			if(have_a){
				for(int j:{i,i+1,i+2}){
					if(j==crw)continue;
					if(Ask(j,crw,imp)==0)ans.pb(j);
				}
				continue;
			}
			bool have_b=false;
			for(int j:{i,i+1,i+2}){
				if(j==imp)have_b=true;
			}
			if(have_b){
				for(int j:{i,i+1,i+2}){
					if(j==imp)continue;
					if(Ask(j,crw,imp)==0)ans.pb(j);
				}
				continue;
			}
			if(r[i]==0){
				if(Ask(i,i+1,crw)==1){
					if(Ask(i,crw,imp)==0){
						ans.pb(i);
						ans.pb(i+2);
					}else{
						ans.pb(i+1);
						ans.pb(i+2);
					}
				}else{
					ans.pb(i);
					ans.pb(i+1);
					if(Ask(i+2,crw,imp)==0)ans.pb(i+2);
				}
			}else{
				if(Ask(i,i+1,imp)==0){
					if(Ask(i,crw,imp)==0)ans.pb(i);
					else ans.pb(i+1);
				}else{
					if(Ask(i+2,crw,imp)==0)ans.pb(i+2);
				}
			}
		}
		printf("! %i ",ans.size());
		for(int i:ans)printf("%i ",i+1);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}