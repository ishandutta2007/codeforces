#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,a,b,c;
char s[N],t[N];
int q[N],op[N];
long long check(int f){
	if (n==1) return 0;
	for (int i=1;i<=n;i++) q[i]=0;
	int m=1;
	t[1]=s[1]; q[1]=1;
	for (int i=2;i<=n;i++){
		if (s[i-1]!=s[i])
			t[++m]=s[i];
		++q[m];
	}
	if (m==1) return (s[1]=='1'?b:a);
	int sc1=0,sc3=0,sm1=0,sm3=0,s2=0;
	*op=0;
	for (int i=1;i<=m;i++)
		if (t[i]=='0'){
			if (i==1||i==m) sc1+=q[i]-1,sc3++;
			else op[++*op]=q[i],sm1+=q[i]-1;
		}
	sort(op+1,op+*op+1);
	for (int i=1;i<=m;i++)
		if (t[i]=='1') s2+=q[i]-1;
	long long re=0,sum=0;
	int p=1;
	for (;p<=*op&&op[p]==1;++p) ++sm3;
	for (;;f^=1){
		if (f==0){
			if (!s2) break;
			re=max(re,sum+=b);
			--s2;
		}
		else{
			if (!s2){	
				if (sc1||sm1) re=max(re,sum+a);
				if (sm3){
					--sm3; ++s2;
					re=max(re,sum-=c);
				}
				else
					break;
			}//no op2
			else{
				if (sm1){
					--op[p]; --sm1;
					for (;p<=*op&&op[p]==1;++p) ++sm3;
					re=max(re,sum+=a);
				}
				else if (sc1){
					--sc1;
					re=max(re,sum+=a);
				}
				else if (sm3){
					--sm3; ++s2;
					re=max(re,sum-=c);
				}
				else if (sc3){
					--sc3;
					re=max(re,sum-=c);
				}
				else
					break;
			}
		}
	}
	//cout<<re<<endl;
	return re;
}
void solve(){
	scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
	printf("%lld\n",max(check(1),check(0)));
} 
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}