#include <stdio.h>
#include <algorithm>
#include <set>
#include <memory.h>

#if (_WIN32||__WIN32__)
	#define I64d "%I64d"
#else              
	#define I64d "lld"
#endif

char s[100500];
int n,m,open[100500],close[100500],kq;
long long res;
std::set<std::pair<int,int> >q;

int main(){
	#ifdef ONLINE_JUDGE
	#else 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	gets(s);n=strlen(s);
	for (int i=0;i<n;i++)if(s[i]=='?')m++;
	for (int i=0;i<m;i++)scanf("%d%d",&open[i],&close[i]);
	for (int i=0,j=0;i<n;i++)
		if (s[i]=='(')kq++;else
		if (s[i]==')'){
			kq--;
			if (kq>=0)continue;
			if (q.empty()){puts("-1");return 0;}
			s[q.begin()->second]='(';
			res+=q.begin()->first;
			q.erase(q.begin());     
			kq+=2;
		}else{
			s[i]=')';
			kq--;
			q.insert(std::make_pair(open[j]-close[j],i));
			res+=close[j];
			j++;
			if (kq<0){
				if (q.empty()){puts("-1");return 0;}
				s[q.begin()->second]='(';
				res+=q.begin()->first;
				q.erase(q.begin());
				kq+=2;
			}
		}
	if (kq!=0){puts("-1");return 0;}
	printf(I64d,res);puts("");
	puts(s);
}