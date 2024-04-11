#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=500050;
int a[N],l[N];
bool was[N],in[N];
int main(){
	int t;scanf("%i",&t);
	while(t--){
		int n;scanf("%i",&n);
		for(int i=1;i<=n;i++)scanf("%i",&a[i]),l[i]=was[i]=in[i]=0;
		int zer=0,pos;
		for(int i=1;i<=n;i++)if(a[i]==0)zer++;
		for(int i=1,o=0;i<=n;i++){
			o+=a[i]==0;
			if(o==zer/2)pos=i;
		}
		for(int i=1;i<=pos;i++)if(a[i])l[a[i]]=i;
		set<pii> st;
		int ans=0;
		for(int i=pos+1;i<=n;i++){
			if(a[i]){
				if(!in[a[i]])st.insert({l[a[i]],a[i]});
				in[a[i]]=1;
			}else{
				if(st.size()){
					ans++;
					was[st.begin()->second]=1;
					st.erase(st.begin());
				}
			}
		}
		for(int i=pos,bal=0;i>=1;i--){
			if(a[i]){
				if(!was[a[i]]&&i==l[a[i]])bal++;
			}else{
				if(bal)bal--,ans++;
			}
		}
		printf("%i\n",min(ans,zer/2));
	}
	return 0;
}