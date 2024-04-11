#include<bits/stdc++.h>
#define N 200005

int T;

int n,a[N],b[N];

bool f[N];
std::set<int> s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			s[i].clear(),f[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			if(i>1&&b[i]==b[i-1])
				s[b[i]].insert(i);
		}
		bool flg=1;
		for(int i=1,j=1;j<=n;j++) if(!f[j]){
			while(i<=n&&a[i]!=b[j]){
				auto it=s[a[i]].upper_bound(j);
				if(it==s[a[i]].end()){
					flg=0;
					break;
				}
				f[*it]=1,s[a[i]].erase(it),i++;
			}
			if(i>n)
				flg=0;
			i++;
		}
		puts(flg?"YES":"NO");
	}
}