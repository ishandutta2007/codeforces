#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=105;
int a[N],d[N],ord[N];
bool was[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i %i",&a[i],&d[i]),ord[i]=i;
	sort(ord+1,ord+1+n,[&](int i,int j){return mp(-a[i],i)<mp(-a[j],j);});
	//for(int j=1;j<=n;j++)printf("(%i %i) ",ord[j],a[ord[j]]);printf("\n");
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!was[ord[i]]&&d[ord[i]]<0){
			a[ord[i]]+=d[ord[i]];
			was[ord[i]]=true;
			bool sw=false;
			for(int j=i;j<n;j++){
				if(mp(-a[ord[j]],ord[j])>mp(-a[ord[j+1]],ord[j+1])){
					swap(ord[j],ord[j+1]);
					ans++;
					sw=true;
				}else break;
			}
			//for(int j=1;j<=n;j++)printf("(%i %i) ",ord[j],a[ord[j]]);printf("\n");
			if(sw)i--;
		}
	}
	for(int i=n;i>=1;i--){
		if(!was[ord[i]]&&d[ord[i]]>0){
			a[ord[i]]+=d[ord[i]];
			was[ord[i]]=true;
			bool sw=false;
			for(int j=i;j>1;j--){
				if(mp(-a[ord[j]],ord[j])<mp(-a[ord[j-1]],ord[j-1])){
					swap(ord[j],ord[j-1]);
					ans++;
					sw=true;
				}else break;
			}
			//for(int j=1;j<=n;j++)printf("(%i %i) ",ord[j],a[ord[j]]);printf("\n");
			if(sw)i++;
		}
	}
	printf("%i\n",ans);
	return 0;
}