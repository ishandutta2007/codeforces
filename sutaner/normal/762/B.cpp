#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define Pii pair<long long int,long long int>
#define maxn 300005
using namespace std;
Pii m[maxn];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	long long int a,b,c,n,ans=0,cnt=0;
	char ch1,ch2;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	scanf("%I64d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%c%c",&m[i].first,&ch1,&ch2);
		if(ch2=='U'){
			m[i].second=0;// USB
			scanf("%c%c%c",&ch1,&ch1,&ch1);
		}
		else{
			m[i].second=1;// PS/2
			scanf("%c%c%c%c",&ch1,&ch1,&ch1,&ch1);
		}
	}
	sort(m,m+n);
	for(int i=0;i<n;i++){
		if(m[i].second==0){
			if(a>0){
				a--;cnt++;
				ans+=m[i].first;
				continue;	
			}
			if(c>0){
				c--;cnt++;
				ans+=m[i].first;
				continue;
			}
		}
		else{
			if(b>0){
				b--;cnt++;
				ans+=m[i].first;
				continue;	
			}
			if(c>0){
				c--;cnt++;
				ans+=m[i].first;
				continue;
			}
		}
	}
	printf("%I64d %I64d",cnt,ans);
	return 0;
}