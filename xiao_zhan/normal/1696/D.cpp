#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l2[300500],st[300500][22],st2[300500][22],a[300500],cur,res;

int chkmx(int l,int r){int k=l2[r-l+1];return max(st[l][k],st[r-(1<<k)+1][k]);}
int chkmn(int l,int r){int k=l2[r-l+1];return min(st2[l][k],st2[r-(1<<k)+1][k]);}

int main(){
	ios::sync_with_stdio(0);
	l2[0]=-1;
	for(i=1;i<=300000;i++){
		l2[i]=l2[i>>1]+1;
	}
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			st[i][0]=a[i];
			st2[i][0]=a[i];
		}
		for(j=1;j<=20;j++){
			for(i=1;i+(1<<j)-1<=n;i++){
				st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
				st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
			}
		}
		cur=1;res=0;
		while(cur!=n){
			int l,r,md,ans=0,sb;
			
			if(a[cur+1]>a[cur]){
				l=cur+1;r=n;
				while(l<=r){
					md=(l+r)/2;
					if(chkmn(cur,md)!=a[cur]){
						r=md-1;
					}
					else{
						l=md+1;ans=max(ans,md);
					}
				}
				sb=chkmx(cur,ans);
				for(i=cur+1;;i++){
					if(a[i]==sb){
						cur=i;break;
					}
				}
			}
			
			else{
				l=cur+1;r=n;
				while(l<=r){
					md=(l+r)/2;
					if(chkmx(cur,md)!=a[cur]){
						r=md-1;
					}
					else{
						l=md+1;ans=max(ans,md);
					}
				}
				sb=chkmn(cur,ans);
				for(i=cur+1;;i++){
					if(a[i]==sb){
						cur=i;break;
					}
				}
			}
			
			res++;
		}
		cout<<res<<'\n';
	}
}