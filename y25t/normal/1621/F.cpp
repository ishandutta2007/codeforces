#include<bits/stdc++.h>
#define ll long long
#define N 100005

int T;

int n,a,b,c;
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
		int A=0,B=0,D=0;
		std::vector<int> C;
		for(int i=1,j=0;i<=n+1;i++,j++)
			if(i>1&&s[i]!=s[i-1]){
				if(s[i-1]=='0'){
					if(i==j+1||i==n+1)
						B+=j-1,D++;
					else
						C.push_back(j-1);
				}
				else
					A+=j-1;
				j=0;
			}
		std::sort(C.begin(),C.end());
		if(c<=b){
			ll ans=0;
			for(auto &x:C){
				while(x&&A){
					x--,ans+=a;
					A--,ans+=b;
				}
				if(!x){
					ans-=c;
					ans+=b;
				}
				else if(!A)
					break;
			}
			while(B&&A)
				B--,ans+=a,A--,ans+=b;
			if(A)
				A--,ans+=b;
			while(D&&A)
				D--,ans-=c,A--,ans+=b;
			for(auto x:C)
				B+=x;
			if(B)
				B--,ans+=a;
			printf("%lld\n",ans);
		}
		else{
			for(auto x:C)
				B+=x;
			if(A==B)
				printf("%lld\n",1ll*A*b+1ll*B*a);
			else if(A>B)
				printf("%lld\n",1ll*(B+1)*b+1ll*B*a);
			else
				printf("%lld\n",1ll*A*b+1ll*(A+1)*a);
		}
	}
}